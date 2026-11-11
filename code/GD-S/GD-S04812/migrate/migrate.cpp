#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa_i;

struct spot{
	int f;
	int p;
	ll len;
};

const int MAXN=2e6+5;
int t,n;
ll p[MAXN],d;
vector<int> cnt[MAXN];
vector<ll> len[MAXN];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&t,&t);
for(int _=0;_<t;_++) {
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&p[i]);
		cnt[i].resize(n+1);
		len[i].resize(n+1);
		for(int j=1;j<=n;j++) {
			cnt[i][j]=0;
			len[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	queue<spot> que;
	for(int i=1;i<=n;i++) {
		que.push({i,i,0});
		len[i][i]=0;
	}
	while(!que.empty()) {
		auto f=que.front();
		que.pop();
		//printf("%d %d %lld\n",f.f,f.p,f.len);
		if(f.len<len[f.f][f.p]) {
			len[f.f][f.p]=f.len;
			cnt[f.f][f.p]=1;
		} else if(f.len==len[f.f][f.p]) {
			cnt[f.f][f.p]++;
		}
		for(int i=n;i>f.p;i--) {
			if(p[i]-p[f.p]<=d) {
				//printf("->%d %lld\n",i,p[i]-p[f.p]);
				que.push({f.f,i,f.len+p[i]-p[f.p]});
			}
		}
	}
	int cc=0;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(cnt[i][j]==2) {
				cc++;
			}
		}
	}
	printf("%d\n",cc);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

