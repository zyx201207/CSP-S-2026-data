#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t,n,d,ans,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if(abs(a[2]-a[1])>d/2||d>=abs(a[n]-a[1])){
				cout<<"0\n";
				continue;
			}
			n-=d/abs(a[2]-a[1])*2-1;
			cout<<n<<"\n";
		}
		return 0;
	}
	return 0;
}

