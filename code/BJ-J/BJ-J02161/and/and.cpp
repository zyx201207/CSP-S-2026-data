#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e5+5;
long long n,m,a[Maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	int mul=a[1];
	for(int i=2;i<=m;i++){
		mul=mul&a[i];
	}
	cout<<mul;
	return 0;
}
