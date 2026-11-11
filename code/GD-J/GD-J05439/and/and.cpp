#include<bits/stdc++.h>
using namespace std;
int count(int n) {
	int sum=0;
	while(n) {
		if(n%2==1) sum++;
		n/=2;
	}
	return sum;
}
bool cmp(int a,int b) {
	return count(a)>count(b)||count(a)==count(b)&&a>=b;
}
int n,m;
int a[200001];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2; i<=m; i++) {
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
