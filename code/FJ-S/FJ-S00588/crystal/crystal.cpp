/*



*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[500010],sum;
queue<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;cin>>s[i],i++);
	sort(s+1,s+n+1);
	q.push(s[1]);
	sum+=s[1];
	for(int i=2;i<=n;i++){
		int w=q.size()*s[i]-sum;
		if(w<=m){
			q.push(s[i]);
			sum+=s[i];
		}else{
			sum-=q.front();
			q.pop();
			sum+=s[i];
			q.push(s[i]);	
		}
	}
	cout<<q.size();
	return 0;
}

