#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],ans[N];stack<int> s;bool bj[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int p=1;p<=n;++p) {
	memset(bj,0,sizeof bj);
	for(int i=p;i<=n;++i) {
		if(!bj[a[i]]) {
		s.push(a[i]),bj[a[i]]=1;
		}
		else {
			while(bj[a[i]]) {
				bj[s.top()]=0,s.pop();
			}
			s.push(a[i]);
		}
	}
	while(!s.empty()) ++cnt[s.top()],s.pop();
	}
	for(int i=1;i<=m;++i) cout<<cnt[i]<<" ";
}
