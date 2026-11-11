#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2*1e6+10;
int n,d,x[maxn],a[maxn],far[maxn];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		a[i]=x[i]-x[i-1];
	}
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>d){
				far[i]=j-1;
				break;
			}
		}
		if(far[i]==0)    far[i]=n;
	}
	int ans1=0;
	for(int i=2;i<=n;i++){
		if(far[i]-far[i-1]==1)    ans1++;
	}
	cout<<ans1<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--)    solve();
}
