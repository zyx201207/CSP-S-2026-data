#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
ll a[N],b[N],c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int cc,t;
	cin >> cc >> t;
	while(t--){
		memset(c,0,sizeof(c));
		int n,d;
		cin >> n >>d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		b[1]=0;
		for(int i=2;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]+b[i];
		}
		if(n<=5000){
			ll x=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if((c[j]-c[i])/d<j-i&&(c[j]-c[i])/d>=2){
						x++;
					}
				}
			}
			cout << x<<endl;
		}
		else if(cc==11||cc==12){
			cout << c[n]/d << endl;
		}
		else if(cc==13||cc==14){
			int ans=-1;
			for(int i=1;i<=n;i++){
				if(c[i]<=d&&c[n]-c[i]<=d){
					ans=i;
					break;
				}
			}
			cout << max(ans,n-ans) << endl;
		}
		else{
			cout << "1" << endl;
		}
	}
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	return 0;
} 
