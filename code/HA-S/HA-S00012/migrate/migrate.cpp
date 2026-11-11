#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5;
int c,t,n,d,x[N],f[N],k,lt,ans,cs;

void solve(){
	cin>>n>>d;
	k=1,ans=0,cs=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=2;i<=n-1;i++)if(x[i]-x[i-1]<=d&&x[i+2]-x[i-1]>d&&x[i+1]-x[i-2]>d)f[i]=1;
	for(int i=1;i<=n;i++){
		if(f[i]==f[i+1]&&f[i]){
			cs++;
			if(cs==1&&lt==i-2)ans++;
			if(cs==2){
				while(k<=lt){
					k++;
					ans++;
				}
				k++,cs--;
				lt=i-2;
			}
		}
		if(x[i]-x[i-1]>d)k=i,lt=0;
	}
	ans++;
	cout<<ans<<"\n";
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
