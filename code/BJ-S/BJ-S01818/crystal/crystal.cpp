#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int l=1,r=2,len=1,t=0;r<=n;r++){
		t+=(a[r]-a[r-1])*len;
		len++;
		while(t>m){
			t-=a[r]-a[l];
			l++;
			len--;
		}
		if(len>ans) ans=len;
	}
	cout<<ans;
	return 0;
}
