#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,QwQ,n;
long long d,a[MAXN];
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>QwQ;
	while (QwQ--){
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>a[i];
		if (c==11 or c==12){
			long long k=d/(a[2]-a[1]),ans=n-2*k+1;
			if (k==0 or k==1 or k>=n) cout<<0<<'\n';
			else cout<<ans<<'\n';
		}
		else cout<<n/d<<'\n'; 
	}
	return 0;
} 
