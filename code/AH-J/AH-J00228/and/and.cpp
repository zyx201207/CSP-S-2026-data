#include<bits/stdc++.h>
using namespace std;
int m,n,a[220005],cnt;
string s[220005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cnt=a[n];
	for(int i=2;i<=m;i++){
		cnt=(cnt & a[n-i+1]);
	}
	cout<<cnt;
	return 0;
}
