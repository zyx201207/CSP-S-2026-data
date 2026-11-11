#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,INF=4e18;
int c,T,n,d,w;
int h[N],de,b;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>h[i];
		}
		if(c==11 or c==12){
			de=h[2]-h[1];
			b=d/de;
			if((d/de)<2){
				cout<<0<<'\n';
			}
			else{
				cout<<max(n-(b*2-1),(int)0)<<'\n';
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			if(h[i]-h[1]<=d and h[n]-h[i]<=d){
				cnt++;w=i;
			}
		}
		if(cnt>1){cout<<0<<'\n';}
		else{
			cout<<(w-1)*(n-w)<<'\n';
		}
	}
	return 0;
}
