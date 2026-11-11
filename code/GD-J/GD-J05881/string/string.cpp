#include <cstdio>
#include <algorithm>
#define ll long long
const int N = 2e5 + 5;
using namespace std;

int n;
int a[N]; char c[N][5];

ll tot,sum,ans,r,pos,tmp,tar;
ll lst[30],cur[30];
ll b[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		scanf("%s",c[i]);
		tot += a[i];
		b[i] = a[i];
	}
	r = n + 1;
	pos = tot + 1;
	for(int i = 1;i <= n && sum < (tot >> 1);i++){
		sum += a[i];
		sum = min(sum,(tot >> 1));
		tar = tot - sum + 1;
		while(tar < pos){
			tmp = min(pos - tar,b[r]);
			pos -= tmp;
			b[r] -= tmp;
			cur[c[r][0] - 'a'] += tmp;
			if(!b[r]) r--;
		}
		for(int j = 0;j < 26;j++){
			if(c[i][0] - 'a' == j) continue;
			ans += cur[j] - lst[j];
		}
		for(int j = 0;j < 26;j++) lst[j] = cur[j];
	}
	printf("%lld",ans);
	return 0;
}

