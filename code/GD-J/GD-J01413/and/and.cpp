#include <bits/stdc++.h>
using namespace std;

int n,k,a[200005],s[200005][35],ans,maxpos;
bool f[200005];

int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i = 1,x,pos;i <= n;i++) {
		scanf("%d",&a[i]);
		x = a[i],pos = 0;
		while (x) {
			maxpos = max(maxpos,pos);
			s[i][pos] = x & 1,pos++;
			x >>= 1;
		} 
	}
	for (int i = maxpos,cnt;i >= 0;i--) {
		cnt = 0;
		for (int j = 1;j <= n;j++) 
			if (!f[j] && s[j][i]) cnt++; 
		if (cnt < k) continue;
		ans += pow(2,i);
		for (int j = 1;j <= n;j++)
			if (!s[j][i]) f[j] = 1;
	}
	printf("%d\n",ans);
	return 0;
} 
