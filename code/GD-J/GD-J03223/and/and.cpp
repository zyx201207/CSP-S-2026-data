#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n;
int m;
int a[N];
int maxn=-1e18;
priority_queue<int> q;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		q.push(a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int maxx=-1e18;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<q.top();
		return 0;
	}
	int ans=q.top();
	q.pop();
	m--;
	while(m--){
		int vv=q.top();
		q.pop();
		ans=(ans&vv);
	}
	cout<<ans;
	return 0;
}
