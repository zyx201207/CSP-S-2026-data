#include<bits/stdc++.h>
using namespace std;
const int MAXX=2e6+5;
int c,t,n,ans,sum,js,ans2;
long long d,x[MAXX];
void dfs(int l,int r){
	for(int i=l+1;i<=r && x[i]-x[l]<=d){
		js++;
		dfs(i,r);
	}
	if(js==sum)
		ans++;
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)
			cin>>x[i];
		for(int i=1;i<=n-1;++i)
			for(int j=i+1;j<=n;++j){
				int p=i;
				sum=1;
				for(int k=p+1;k<=j;++k){
					if(x[k]-x[p]>d){
						sum++;
						p=k-1;
					}
				}
				js=0;
				if(ans==2)
					ans2++;
			}
		cout<<ans2<<"\n";
	}
	return 0;
}
