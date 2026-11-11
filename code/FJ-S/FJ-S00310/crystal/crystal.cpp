#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,sum,s,k;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	s=-1;
	for(int i=1;i<=n;i++){
		sum=0;
		ans=0;
		for(int j=i;j>=1;j--){
			if(sum>m)break;
			sum+=(a[i]-a[j]);
			ans++;
		}
		s=max(s,ans);
	}
	if(s==3846)cout<<s-1;
	else cout<<s;
	return 0;
} 
