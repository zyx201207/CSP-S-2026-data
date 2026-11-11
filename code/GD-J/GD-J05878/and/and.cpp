#include<bits/stdc++.h>
using namespace std;
const long long N=1e7+10;
long long n,m,ans;
long long a[N];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	ans=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
