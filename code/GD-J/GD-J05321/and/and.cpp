#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	cnt=a[m];
	for(int i=m; i>=2; i--) {
		cnt=cnt||a[i];
	}
	if(m==1)cout<<a[1];
	else cout<<cnt;
}
