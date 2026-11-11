#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[10001111],sum=0;
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=a[1];i<=a[n];i++){
		int f=i;
		int ans=0,cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]>f) break;
			else ans+=abs(f-a[j]);
			
			if(ans>m) break;
			else cnt++;
		}
		sum=max(sum,cnt);
	}
	cout<<sum;
} 
