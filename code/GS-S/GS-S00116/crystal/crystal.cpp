#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5;
int a[N];
int ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(n<=5000){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			int w=m;
			int sum=1;
			for(int j=i-1;j>=1;j--){
				if(a[j]+w>=a[i]){
					sum++;
					w-=a[i]-a[j];
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	else{
		int w=a[2]-a[1];
		int v=1;
		while(m>=0){
			ans++;
			m-=w*v;
			v++;
		}
		cout<<ans-1;
		return 0;
    }
}

