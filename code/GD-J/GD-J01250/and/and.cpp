#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans;
vector<int> v[2];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],v[0].push_back(a[i]);
	for(int i=31,p=0;i>=0;i--,p^=1){
		int cnt=0;
		for(int x:v[p])if(x&(1<<i))cnt++;
		if(cnt<m){v[p^1]=v[p];continue;}
		v[p^1].clear();
		for(int x:v[p])if(x&(1<<i))v[p^1].push_back(x);
		ans|=(1<<i);
	}
	cout<<ans;
}
