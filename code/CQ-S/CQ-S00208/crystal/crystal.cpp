#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
queue<int>q;
int n,m,a[N],s,b,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		while(b*a[i]-s>m){
			int t=q.front();
			q.pop();
			b--;
			s-=t;
		}
		ans=max(ans,b);
		b++;
		s+=a[i];
		q.push(a[i]);
	}
	cout<<ans+1;
	return 0;
}
