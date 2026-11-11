#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+5;
LL a,b,c,d,e,ans;
LL Time[505],tme[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>e>>a>>b>>c>>d;
	for(int i=1;i<=b;i++)cin>>Time[i];
	for(int i=1,k;i<=b;i++){
		cin>>k;
		for(int j=1,s;j<=k;j++){
			cin>>s>>tme[j];
		}
		sort(tme+1,tme+k+1);
		ans+=tme[1];
	}
	for(int i=1;i<=d;i++){
		LL a,b;
		cin>>a>>b;
		cout<<ans<<'\n';
	}
	return 0;
} 
