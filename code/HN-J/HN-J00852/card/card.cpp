#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+50;
long long a[N],last[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		last[a[i]]=i;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			ans[a[j]]++;
			j=last[a[j]];
		}
	}
	for(long long i=1;i<=m;i++){
		cout << ans[i];
		if(i<m) cout << " ";
	}
	cout << endl;
}
