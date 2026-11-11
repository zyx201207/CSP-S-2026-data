#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt,cnt2,ans,mx;
int a[200010],b[60],t[200010],t2[200010];
int lowbit(int x){
	return x & -x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
		t2[++cnt2] = a[i];
		int x = a[i];
		while (x){
			b[(int)log2(lowbit(x))]++;
			x -= lowbit(x);
		}
	}
	int id = -1;
	for (int i = 31;i >= 0;i--)
		if (b[i] >= m) {
			id = i;
			break;
		}
	if (id == -1) {
		cout<<0;
		return 0;
	}
	while (1){
		cnt = 0;
		for (int i = 1;i <= cnt2;i++){
			int x = t2[i];
			while (x){
				if ((int)log2(lowbit(x)) == id) {
					t[++cnt] = t2[i];
					break;
				}
				x -= lowbit(x);
			}
		}
		if (cnt == m) break;
		for (int i = 31;i >= 0;i--) b[i] = 0;
		for (int i = 1;i <= cnt;i++){
			int x = t[i];
			while (x){
				if ((int)log2(lowbit(x)) < id) 
					b[(int)log2(lowbit(x))]++;
				x -= lowbit(x);
			}
		}
		id = -1;
		for (int i = 31;i >= 0;i--)
			if (b[i] >= m) {
				id = i;
				break;
			}
		if (id == -1) break;
		cnt2 = 0;
		for (int i = 1;i <= cnt;i++)
			t2[++cnt2] = t[i];
	}
	int ans = t[1];
	for (int i = 2;i <= m;i++)
		ans &= t[i];
	cout<<ans;
	return 0;
} 
