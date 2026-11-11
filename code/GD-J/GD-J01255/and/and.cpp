#include<bits/stdc++.h>
#define ull unsigned long long
ull a[200050];
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ull n,m;
	cin>>n>>m;
	for(ull i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int ans=a[1]; 
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
