#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int md=l+r>>1;
			int len=i-md+1;
			if(len*a[i]-(s[i]-s[md-1])<=m)r=md;
			else l=md+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
} 
