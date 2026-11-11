#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5,M=1e4+5;
int c,t;
ll n,d;
ll a[N],dp[M][M],ch[N];
bool f;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d>abs(a[1]-a[n])){
			cout<<"0\n";
			continue;
		}
		ll cha=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=cha){
				f=1;
				break;
			}
		}
		if(!f){
			if(d<cha*2){
				cout<<"0\n";
			}else if(d>=abs(a[1]-a[n])){
				cout<<"0\n";
			}else{
				ll c=d/cha;
				c*=2;
				cout<<n-c+1<<'\n';
			}
			continue;
		}
	}
	return 0;
}
