#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
    	ll n,d,ans=0,tmp=1,tmp1=0,tmp2=0;
    	cin>>n>>d;
    	ll a[n],b[n][n],c[n]={0},f[n]={0};
    	for(int j=0;j<n;j++){
    		cin>>a[j];
		}
		b[0][0]=a[0];
		for(int j=1;j<n;j++){
    		if(a[j]-a[j-1]<=d){
    			b[tmp][tmp1]=a[j];
    			tmp++;
			}
			if(a[j]-a[j-1]>d){
				c[tmp2]=tmp;
				f[tmp2]=j;
				tmp=0;
				tmp1++;
				tmp2++;
    			b[tmp][tmp1]=a[j];
    			tmp++;
			}
		}
		if(c[0]!=0)
		for(int p=0;p<tmp2;p++){
			for(int j=0;j<c[p]-d;j++){
    		    for(int k=j+d;k<c[p];k++){
    		        if((b[k][p]-b[j][p])%d==d-1){
    		        	ans++;
				    }
		        }
	    	}
		}
		else for(int j=0;j<tmp-d;j++){
    		for(int k=j+d;k<tmp;k++){
    		    if((b[k][0]-b[j][0])%d==d-1){
    		    	ans++;
				}
		    }
		}
		cout<<ans<<endl;
	}
}