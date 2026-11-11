#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x<y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long a[200005];
	long long flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) flag=1;
	}
	stable_sort(a+1,a+n+1,cmp);
	if(flag==1) cout<<a[n-1];
	else cout<<n-2;
}
