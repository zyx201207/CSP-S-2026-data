#include<bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("subway.in","r",stdin)
	freopen("subway.out","w",stdout)*/
	long long c,n,m,d,p;//n,m,d,q分别表示地铁线路数，地铁站数，每个地铁站最多被几条线路经过，以及出行计划数。
	cin>>c>>n>>m>>d>>p;
	long long w[m];
	long long time=0,station;
	for(long long in=0;in<m;in++)cin>>w[in];
	long long i[n][d];
	for(long long temp0=0;temp0<n;temp0++){
	    cin>>i[temp0][0];
	    for(long long temp1=1;temp1<=(i[temp0][0]*2);temp1++)cin>>i[temp0][temp1];
    }
    long long x[p],y[p];
    for(long long r=0;r<p;r++)cin>>x[r]>>y[r];
    for(long long r=0;r<p;r++){
    	time=0;
   	    time=time+w[x[r]];
   	    while((x[r]+station)==y[r]){
   	        for(long long temp0=0;temp0<n;temp0++){
   	    	    station=0;
   		        for(long long temp1=1;temp1<=i[temp0][0];temp1=temp1+2){
    			    if(x[r]+station==temp1){
    			        station++;
    			        time=time+i[r][temp1+1];
			            if((x[r]+station)==y[r])break;
			        }
		        }
		    }
	    }
	    time=time+w[y[r]];
	    cout<<time<<endl;
	}
    return 0;//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
}
