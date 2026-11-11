#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans,c,t,d,h,f[5000005];
ll x[2000005],mn;
void check(int xx,int y,long long step){
	if(xx>y) return; 
	else if(xx==y){
		f[step]++;
		mn=min(mn,step);
	}
	else{
		for(int i=xx+1;i<=y;i++){
			if(x[i]-x[xx]<=d){
				check(i,y,step+1);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		ans=0;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			for(int k=1;k<j;k++){
				h=0;
				memset(f,0,sizeof f);
				mn=2e6+5;
				check(k,j,0);
				if(f[mn]==2) ans++; 
				if(h==1) cout<<k<<" "<<j<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
