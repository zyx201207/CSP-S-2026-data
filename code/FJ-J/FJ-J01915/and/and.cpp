#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;
ll a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	if(m==1){//测试点6  只有一个就输出最大值 
		cout<<a[n];
		return 0;
	}
	
	if(m==n){//测试点7(m==n全部按位与) 
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	
	if(m==2){//测试点8~10 
		ll ans=0;
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));	
			}
		}
		cout<<ans;
		return 0;
	}
	
	//测试点13 
	cout<<a[n-m+1];
	
	return 0;
}
