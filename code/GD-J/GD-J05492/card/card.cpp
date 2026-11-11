#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN=5e5+5,MAXM=3e5+5;

int cnt[MAXM],p[MAXN],n,m;
int t[MAXM],ind[MAXM],que[MAXM];
int nxt[MAXN],_nxt[MAXM];
int d[MAXN],s[MAXN];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&p[i]);
	}
	
	for(int i=n;i;i--) {
		if(!_nxt[p[i]]) _nxt[p[i]]=i;
		nxt[i]=_nxt[p[i]];
		_nxt[p[i]]=i;
	}
	
//	for(int i=1;i<=n;i++) {
//		printf("%d ",nxt[i]);
//	}
//	printf("\n");
	
	for(int i=1;i<=n;i++) {
		int bk=0;
		for(int j=i;j<=n;j++) {
			if(ind[p[j]]&&t[p[j]]==i) {
				bk=ind[p[j]];
			} else {
				que[++bk]=p[j];
				ind[p[j]]=bk;
				t[p[j]]=i;
			}
		}
		for(int i=1;i<=bk;i++) {
			//printf("%d ",que[i]);
			cnt[que[i]]++;
		}
		//printf("\n");
	}
	
	for(int i=1;i<=m;i++) {
		printf("%d ",cnt[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

