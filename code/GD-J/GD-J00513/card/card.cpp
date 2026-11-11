#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn],cnt[maxn];
int head[maxn],tail[maxn],pr[maxn],num;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		tail[a[i]]++;
		cnt[a[i]]++;
	}
	cnt[a[n]]=n;
	for (int i=1;i<=n;i++){
		tail[a[i]]--;
		head[a[i]]++;
		int tmp=pr[a[i]];
		pr[a[i]]=min(head[a[i]],tail[a[i]]);
		num+=(pr[a[i]]-tmp);
		if (i!=1&&i!=n&&a[i]!=a[n]){
			if ((num-pr[a[i]])<=0)
				cnt[a[i]]++;
		}
	}
	for (int i=1;i<=m;i++)
		cout << cnt[i] << ' ';
	return 0;
}
