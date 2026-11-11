#include <cstdio>
#define ll long long
const int N = 2e6 + 5;
using namespace std;

int c,t;
int n,d;
int x[N];

bool ok;
ll ans;

void solve(){
	scanf("%d%d",&n,&d);
	for(int i = 1;i <= n;i++) scanf("%d",&x[i]);
	ans = 0;
	for(int l = 1;l < n - 2;l++){
		for(int r = l + 3,pos,cnt;r <= n;r++){
			ok = true;
			pos = l;
			cnt = 0;
			while(pos < r){
				if(pos + 3 <= r && x[pos + 2] - x[pos] <= d && x[pos + 3] - x[pos + 2] <= d && x[pos + 1] - x[pos] <= d && x[pos + 3] - x[pos + 2] <= d && x[pos + 3] - x[pos] > d){
					cnt++;
					if(1 < cnt) break;
				}
				else if(x[pos + 1] - x[pos] > d){
					ok = false;
					break;
				}
				pos++;
			}
			if(ok && cnt == 1) ans++;
		}
	}
	printf("%lld\n",ans);
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}

