#include <iostream>
using namespace std;

const int N = 500005;

int n,m,a[N];
int tab[N];
int b[N];
int ans[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int tail;
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int i=1; i<=n; i++) {
		tail=0;
		for (int o=1; o<=n; o++) b[o]=0;
		for (int j=i; j<=n; j++) {
			if (b[a[j]] != 0) {
				for (int o=b[a[j]]+1; o<=tail; o++) b[tab[o]]=0;
				tail=b[a[j]];
			} else {
				tail++;
				tab[tail]=a[j];
				b[a[j]]=tail;
			}
		}
		for (int i=1; i<=tail; i++) {
			ans[tab[i]]++;
		}
	}
	for (int i=1; i<=m; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
