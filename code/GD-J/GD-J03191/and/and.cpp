#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;;
long long a[N];
long long n,m,sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	cout<<a[m];
	return 0;
}
