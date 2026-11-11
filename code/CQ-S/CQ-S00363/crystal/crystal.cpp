#include<bits/stdc++.h>
using namespace std;
void fast(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fast();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	int sum=0;
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(int)q.size();
		while(!q.empty()&&sum>m){
			sum-=a[i]-q.top();
			q.pop();
		} 
		q.push(a[i]);
		ans=max(ans,(int)q.size());
	}
	cout<<ans;
	return 0;
}

