#include <bits/stdc++.h>
using namespace std;

int n,m,a[10005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxn=-100;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if ((a[i]&a[j])>maxn) maxn=(a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
}
