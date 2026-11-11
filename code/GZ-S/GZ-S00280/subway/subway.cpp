//遵义航天高级中学 赵奕钦 考号GZ-S00280 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t1[100],t2[100][100],a[100][100],k1[100],xr[100],yr[100],lu[100][100],ans[100];
int dp(int x,int y){
	int q1[100],q2;
	for(int i=0;i<m;i++){					
	    if(lu[x][i]!=0){
		if(i==y){
			return lu[x][i];
		}	    
		  q1[i]+=dp(i,y);
    }
    for(int i=0;i<m-1;i++){
    	q2=(q1[i],q1[i+1]);
	}
	return q2;				
}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>t1[i];
	}
	for(int i=0;i<n;i++){
		cin>>k1[i];
		for(int j=0;j<k1[i];j++){
            cin>>a[i][j];
			cin>>t2[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>xr[i]>>yr[i];
		ans[i]=100000000000;
	}
	for(int o=0;o<n;o++){	
		for(int i=0;i<m;i++){
			int r=0,l=0;
			for(int j=i+1;j<m;j++){
				for(int g=0;g<k1[o];g++){
					if(a[o][q]==i)r=1;					
				}
				for(int g=0;g<k1[o];g++){
					if(a[o][j]==i)l=1;					
				}
			    if(r==1&&l==1){
					lu[i][j]=t2[o][i]+t2[o][j];								
			    }					
			}
											
		}
	}
	for(int i=0;i<q;i++){
		cout<<dp(xr[i],yr[i])<<endl;
		ans[i]=min(ans[i],dp(xr[i],yr[i]));
		cout<<ans[i]<<endl;
	}							
	return 0;
	}
