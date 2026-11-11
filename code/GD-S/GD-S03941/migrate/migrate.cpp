#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int MAXN = 2e6+5;
int c,T;
int n,d;
int a[MAXN];
int used[MAXN];
long long ans;


signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans = 0;
		memset(used,0,sizeof(used));
		memset(a,0,sizeof(a));
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		for(int i = n;i>=2;i--){
			a[i] -= a[i-1];
		}
		a[1] = 0;
		for(int i = 1;i<=n;i++){
			a[i] += a[i-1];
		}
		for(int i = 1,j = 2;j<=n;){
			if(a[j]-a[i]<=d){
				used[j] = used[i]+1;
				j++;
			}
			else{
				i++;
			}
		}
		for(int i = 1,j = 2;j<=n;){
			if(used[j]-used[i]==2){
				int cnt = 0;
				for(int k = i+1;k<j;k++){
					if(used[k]-used[i]==1&&used[j]-used[k]==1){
						cnt++;
					}
					if(cnt>2)break;
				}
				if(cnt==2){
					ans++;
				}
				j++;
			}
			else if(used[j]-used[i]>2){
				i++;
			}
			else{
				j++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
