#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+3;
int n,ret=1;
long long m,a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	queue<long long> q;
	q.push(a[1]);
	long long sum=0;
	for(int i=2;i<=n;i++){
		sum+=1LL*q.size()*(a[i]-a[i-1]);
		while(sum>m && !q.empty()){
			sum-=a[i]-q.front();
			q.pop();
		}
		q.push(a[i]);
		ret=max(ret,(int)q.size());
	}
	cout<<ret<<"\n";
	return 0;
}
