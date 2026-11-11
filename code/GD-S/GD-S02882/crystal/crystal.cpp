#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int n,m,a[maxn],ans=0,sum[maxn];
deque<int>qu;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1,all=a[1];
	ans=1;
	qu.push_back(1);
	while(r<=n){
		qu.push_back(r);
		while(1){
			all=a[qu.back()]*qu.size();
			int nw=sum[qu.back()]-sum[qu.front()-1];
			if(all>nw+m)qu.pop_front();
			else break;
		}
		ans=max(ans,(long long)qu.size());
		r++;
	}
	cout<<ans<<endl;
	return 0;
}
