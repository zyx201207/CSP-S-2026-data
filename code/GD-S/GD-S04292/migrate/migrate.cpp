#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,a[2100005],t;
ll n,m,x[5005][5005],y[5005][5005],c,d,p,r,sum,ans,o;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>6){
			cout<<0<<"\n";
			continue;
		}
		for(int z=1;z<=n;z++){
			o=0;
			bool fl=0;
			for(int i=z;i<n;i++){
				int j=i+1;
				o++;
				if(j<=n&&abs(a[j]-a[i])>d){
					fl=1;
				}
				if(fl)y[z][j]=1;
				while((j+1)<=n&&abs(a[(j+1)]-a[i])<=d){
					x[z][j]=o;
					j++;
				}
				i=j-1;
				x[z][j]=o;
			}
		} 
		for(int z=1;z<n;z++){
			for(int i=z+3;i<=n;i++){
				p=0;
				if(x[z][i]<=1||y[z][i])continue;
				for(int j=z+1;j<i;j++){
					if(x[z][j]+x[j][i]==x[z][i]){
						p++;
					}
				}
				if(p==2){
					ans++;
				}
			}
		} 
		cout<<ans<<"\n";
	}
	return 0;
}
