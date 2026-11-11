#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,a[500011];
int v[500011];
int lst[300011];
int ans[300011];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		v[i]++;
		v[lst[a[i]]+1]+=v[i];
	}
	for(int i=1;i<=n;i++)
		ans[a[i]]+=v[i];
	for(int i=1;i<=m;i++)
		cout << ans[i] << ' ';
	return 0;
}
