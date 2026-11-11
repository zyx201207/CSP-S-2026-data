#include <cstdio>
#define ll long long
const int N = 2e5 + 5;
using namespace std;

int n,m;
int a[N];

int ans;
int nxt[N],tmp[N];

int find(const int& x){
	return nxt[x] != x ? nxt[x] = find(nxt[x]) : x;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		nxt[i] = i;
	}
	nxt[n + 1] = n + 1;
	for(int pos = 30,mask,cnt;pos >= 0;pos--){
		mask = (1 << pos);
		cnt = 0;
		for(int i = 1;i <= n + 1;i++) tmp[i] = nxt[i];
		for(int i = find(1);i <= n;i = find(i + 1)){
			if(mask & a[i]){
				cnt++;
			}
			else nxt[i] = find(i + 1);
		}
		if(cnt >= m) ans += mask;
		else{
			for(int i = 1;i <= n + 1;i++) nxt[i] = tmp[i];
		}
	}
	printf("%d",ans);
	return 0;
}

