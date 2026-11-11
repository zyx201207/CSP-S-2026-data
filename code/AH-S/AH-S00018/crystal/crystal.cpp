#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,i,m,maxn;LL a[500005],ans=1,sum=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		}
		
	sort(a+1,a+n+1);
	
	for(int i = 2;i <= n;i ++){
		if(a[i]==a[i-1]) sum ++;
		else{
			maxn = max(maxn,sum);
			sum = 1;
			}
		}
	
	i = 1;	
	while((m >= (a[i+1]-a[i])*i) && (i+1 <= n)){
		ans ++;
		m-=(a[i+1]-a[i])*i;
		i++;
		}	
		if(maxn > ans){
			cout << maxn ;
			return 0;
			}
	cout << ans;
	
	return 0;
}
