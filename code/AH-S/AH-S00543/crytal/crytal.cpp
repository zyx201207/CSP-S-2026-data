#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
const int N=5e5+2;
int n;
long long m,a[N],maxn=-1e18,minn=1e18,cnt=0,ans=-1;
bool check(int k){
	cnt=0;
	priority_queue<long long,vector<long long>,greater<long long>> q;
	for(int i=0;i<n;i++) q.push(abs(k-a[i]));
	long long tmp=m,c=0;
	while(1){
		tmp-=q.top();
		if(tmp<0) break;
		cnt++;
		c+=q.top();
		q.pop();
	}
	return c<=m?1:0;
}
int main(){
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	for(int i=minn;i<=maxn;i++){
		if(check(i)) ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
