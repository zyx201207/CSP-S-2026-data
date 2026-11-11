#include <bits/stdc++.h>
using namespace std;
long long n,m;
int ans=0;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=m;i>=1;i--){
		for(int j=1;j<=n;j++)
		{
			a[j]++;
			if(a[i+j]==a[j])
				ans++;
			
		}
	}
	cout << ans;
	return 0;
}
