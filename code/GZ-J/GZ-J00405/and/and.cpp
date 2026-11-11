//GZ-J00405 华东师范大学附属贵阳学校 刘凌舟 
#include <bits/stdc++.h>
using namespace std;

int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	
	return 0;
}
