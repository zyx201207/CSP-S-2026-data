#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	ll s=a[1];
	for(int i=2;i<=m;i++){
		s&=a[i];
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
