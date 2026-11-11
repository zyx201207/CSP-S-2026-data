#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int n,m;
int a[N];
int c[N],pre[N];
int ans=1;
unordered_map<int,int>mp;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int last=a[2]-a[1],lastcnt=1;
	for(int i=2;i<=n;i++){
		if(m<=0)break;
		if(m-lastcnt*(a[i]-last)>=0){
			m-=lastcnt*(a[i]-last);
			lastcnt++;
			last=a[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}