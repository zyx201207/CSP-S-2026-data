#include <bits/stdc++.h> 
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int mid=(1+n)/2;
	int i=mid-1;
	for(int i=1;i<=n;i++){
		if(i==mid)continue;
		else{
			if(a[i]==a[mid])ans++;	
		}
	}
	while(m>0&&i>=1){
		if(m>=a[mid]-a[i]){
			m-=a[mid]-a[i];
			i--;
			ans++;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
