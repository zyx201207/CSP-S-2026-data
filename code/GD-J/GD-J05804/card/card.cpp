#include <cstdio>
#include <stack>
static char ib[1 << 20], ob[1 << 20];
int n, m, a[(int)5e5+1], k;
bool have[(int)3e5+1];
int count[(int)3e5+1];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	std::scanf("%d %d", &n, &m);
	std::printf("%d %d", n, m);
	for (int i=1;i<=n;i++) std::scanf("%d", &a[i]);
	for (int i=1;i<=n;i++) {
		std::stack<int> desk;
		for (int j=1;j<=m;j++) have[m]=0;
		for (int l=i;l<=n;l++) {
			k=a[l];
			if (have[k]) {
				while (desk.top() != k) {have[desk.top()]=0; desk.pop();}
			} else {
				desk.push(k);
				have[k]=1;
			}
		}
		for (int j=1;j<=m;j++) if (have[j]) count[j]++;
	}
	std::printf("%d", count[1]);
	for (int i=2;i<=m;i++) std::printf(" %d", count[i]);
	std::printf("\n");
	return 0;
}
		
