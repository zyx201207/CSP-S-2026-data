

#include <bits/stdc++.h>
#define int long long
#define f(i,a,b) f(int i =(a);i<=(b);i++)
using namespace std;
deque<int> q;
int ans[200005];
int inq[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[200005];
	for(int i=1;i<=n;i++){
		cin >> a[i];
}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		q.push_front(a[j]);
		inq[a[j]]++;
		if (inq[a[j]]>=2){
			while(!q.empty()&&q.back()!=a[j]){
				inq[q.back()]--;
				//cout << q.back() << ' ';
				q.pop_back();
			}
			q.pop_back();
			inq[a[j]]=1;
		}
	}
	for (int k=1;k<=m;k++){
		if (inq[k]){
			ans[k]++;
	}
}
}
for (int i=1;i<=m;i++){
	cout << ans[i] << ' ';
}
	return 0;
}

