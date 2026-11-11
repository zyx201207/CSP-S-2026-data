//华东师范大学附属贵阳学校 陈睿阳 GZ-J00418 
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			cnt[a[j]]++;
			if (a[j]==a[j-1])cnt[a[j]]--;
		}
	}
	for (int i=1;i<=m;i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
