#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll pre[N],n,x[N],d,c;
void init(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(n<=3)cout<<"0\n";
	if(c==11||c==12||c==0){
		ll delta=x[2]-x[1];
		ll p=d/delta;
		if(p<=1){
			cout<<"0\n";
			return;
		}
		ll f=p*2-1;
		cout<<max(n-f,0ll)<<"\n";
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--)init();
	return 0;
}
//score: 10 points
