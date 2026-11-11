#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+9;
int a[N];
void solved()
{
	int n; ll m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sum=1,ans=1;
	for(int i=1;i<=n;i++)
	{
		ll cnt=0; sum=1;
		for(int j=i+1;j<=n;j++){
			cnt+=((a[j]-a[j-1])*(j-i)); 
			if(cnt>m){
				
				break;
			}
			else sum++; 
			
		}
		if(sum>ans) ans=sum;
	}
	cout<<ans;
}
int main()
{
	//-std=c++14-Wl,--stack=100000000
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	solved();
	return 0;
}
