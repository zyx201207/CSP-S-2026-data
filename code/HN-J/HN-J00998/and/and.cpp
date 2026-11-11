#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=(1<<31)-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=n;i>n-m;i--)ans=(ans&a[i]);
	cout<<ans;
	return 0;
}
