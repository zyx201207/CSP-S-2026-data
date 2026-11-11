#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}sort(a+1,a+n+1,greater<int>());
	int s=a[1];
	for(int i=1;i<=m;++i)s&=a[i];
	cout<<s;
	return 0;
}
//75AC
