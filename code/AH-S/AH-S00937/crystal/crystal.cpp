#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans++;
		m-=a[i];
		if(m<0) break;
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
