#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010];
int t[50];
int ans=0;
bool cant[200010];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(cant[j]) continue; 
			if(a[j]&(1LL<<i)) cnt++;
		}
		if(cnt>=m){
			ans+=1<<i;
			for(int j=1;j<=n;j++){
				if(!(a[j]&(1LL<<i))) cant[j]=true;
			}
		}
	}
	cout<<ans;
	return 0;
}
