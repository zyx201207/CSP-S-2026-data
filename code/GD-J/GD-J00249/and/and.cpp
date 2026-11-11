#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		cout<<a[n]&a[n-1];
		return 0;
	}
	ans=a[n-m+1];
	for(int i=n-m+2;i<=n;i++)
		ans&=a[i];
	cout<<ans;
	return 0;
}
