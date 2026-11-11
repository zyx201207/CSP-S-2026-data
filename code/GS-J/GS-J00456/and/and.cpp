#ioclude<bits/stdc++.h>
using namespace std;
const int M=2e5+5 ;
long long a[M];
char p[M];
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    int n;
    cin>>n;
    long long m=0;
    for(int i=1,i<=n;i++){
	    cin>>a[i]>>p[i];
	    m+=a[i];
    }
    m/=2;
    int l=1,m=0,c=0,cnt=0;
    int i=l,j=n;
    while(c<=m){
        if(c+l<=m){
	        if(l<m){	        	
			}
	    }
    }
    return 0;
}
