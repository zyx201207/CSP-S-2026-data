#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[1000010],sum,ans;
deque <long long> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int r=1;r<=n;r++){
		q.push_back(a[r]);
		sum+=a[r];
		while(!q.empty()&&a[r]*q.size()-sum>m){
			sum-=q.front();
			q.pop_front();
		}
		long long now=q.size();
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}
