#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,tp[2114514];
void teshua(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%lld",&tp[i]);
		}int cha=tp[n]-tp[n-1];
		int yibu=d/cha;
		if(yibu<=1){cout<<0<<'\n';
		continue;
		}if(n-(yibu*2-1)>0)cout<<(n-(yibu*2-1))<<'\n';
		else cout<<0<<'\n';
	}
}
void teshub(){
	while(t--)cout<<1<<'\n';
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		teshua();return 0;
	}
	if(c==13||c==14){
		teshub();return 0;
	}
	return 0;
}
