#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,l=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int x=i-l;
		s[i]=(i-1-l)*(a[i]-a[i-1])+s[i-1];
		while(s[i]>m){
			l++;
			s[i]-=a[i]-a[l];
			x--;
		}ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}

