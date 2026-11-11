//t4 card
#include <iostream>
#include <vector>
using namespace std;
const int maxn=5e5+5;
int a[maxn];
int n,m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	vector<int> ans(m+1,0);
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		vector<int> v;//×ÀÉÏµÄÅÆ 
		for (int j=i;j<=n;j++) {
			int len=v.size();
			for (int k=0;k<len;k++) {
				if (a[j]==v[k]) {
					for (int l=k;l<len;l++) v.pop_back();
					break;
				}
			}
			v.push_back(a[j]);
		}
		for (int j:v) {
			ans[j]++;
		}
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
