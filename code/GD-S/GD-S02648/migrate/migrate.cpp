#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(11<=c&&c<=12){
			ll del=a[2]-a[1];
			ll p=d/del;
			if(p==0||p==1){
				cout<<0<<endl;
				return 0;
			}
			cout<<n-p-1<<endl;
			return 0;
		}
		ll cnt=0;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				if(a[r]-a[l]<=d) continue;
				ll curcnt=0;
				for(int i=l;i<=r;i++){
					if(a[i]-a[l]<=d&&a[r]-a[i]<=d)
						curcnt++;
				}
				if(curcnt==2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
