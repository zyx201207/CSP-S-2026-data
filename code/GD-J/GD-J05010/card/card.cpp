#include<bits/stdc++.h>
using namespace std;

int n, m, a[500005], s[500005], l, ans[300005];		
bool b[300005] ={0};

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++){
		l=0;
		memset(b, false, sizeof(b));
		memset(s, 0, sizeof(s));
		for (int j=i; j<n; j++){
			if (!b[a[j]]){
				s[++l]=a[j];
				b[a[j]]=1;
			} else if (b[a[j]]){
				while (s[l]!=a[j] && l>0) {
					b[s[l]]=0;
					l--;
				}
			}
		}
		while (l>0){
			ans[s[l]]++;l--;
		}
	}
	for (int i=1; i<=m; i++)
		cout << ans[i] << " ";
	return 0;
}
