#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int a[N];
int s[N];
int ans[M];
int n,m;
int find(int len,int x) {
	if (len < 1) return -1;
	for (int i = 1;i <= len;i ++) {
		if (s[i] == x) return i;
	}
	return -1;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 1;i <= n;i ++) scanf(" %d",&a[i]);
	for (int i = 1;i <= n;i ++) {
		int len = 0; 
		for (int j = i;j <= n;j ++) {
			int k = a[j];
			int tmp = find(len,k);
			if (tmp == -1) {
				s[len + 1] = k;
				len ++;
			}else {
				int index = tmp;
				len = index;
			}
		}
		for (int j = 1;j <= len;j ++) {
			ans[s[j]] ++;
		}
	}
	for (int i = 1;i <= m;i ++) {
		printf("%d",ans[i]);
		if (m != i) printf(" ");
	}
	return 0;
}
