#include<bits/stdc++.h> 
using namespace std;
#define int long long
	int m,n,a[100010],b=0,c,d;
	
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
   	cin>>a[i];
	}
	sort(a,a+n+1);
	cout<<a[n-2];
		return 0;
}
