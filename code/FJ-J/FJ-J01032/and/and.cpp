#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	long long r=a[1]&a[2];
	long long f=r&a[3];
	cout<<f;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	return 0;
}
