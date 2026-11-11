#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5, M = 3e5+5;
int n, m, a[N], d1cnt[M], ptr, vis[M], table[N],cnt[N],d2,d2a[N];
bool d1 = true;
int read(){
	char c = getchar();
	int k=0;
	while(c>='0'&&c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return k;
}
void print(int x){
	if(x/10!=0)print(x/10);
	putchar((x%10)+'0');
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n=read();m=read();
	for (int i = 1; i <= n; i++) {
		a[i]=read();
		d2a[i]=a[i];
		if (a[i] < a[i - 1])d1 = false;
		if(a[i]!=a[i-1])d2++;
	}
	if (d1) {
		for (int i = 1; i <= n; i++)d1cnt[a[i]]++;
		for (int i = 1; i <= m; i++) {
			print((d1cnt[i] += d1cnt[i - 1]));putchar(' ');
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		ptr = 1;
		memset(vis, 0, sizeof vis);
		memset(table, 0, sizeof table);
		for (int j = i; j <= n; j++) {
			if((vis[a[j]]>ptr)||(table[vis[a[j]]]!=a[j]))vis[a[j]]=0;
			if (vis[a[j]] == 0)vis[a[j]]=ptr;
			else ptr=vis[a[j]];
			table[ptr++]=a[j];
		}
		for(int i=1;i<ptr;i++){
			cnt[table[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		print(cnt[i]);putchar(' ');
	}
}
