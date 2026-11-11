#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005],pre[500005],maxn,now,num=0;
priority_queue<long long,vector<long long>,greater<long long> >q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=n;
	sort(a+1,a+n+1);
	maxn=a[n];
	for(int i=1;i<=n;i++){
		long long nowuse=0;
		q.push(a[i]-maxn);
		nowuse=(i-1-num)*a[i]-(now+(i-1-num)*maxn);
		if(nowuse>m){
			now-=q.top();
			q.pop();
			ans--;
			num++;
		}
		now+=a[i]-maxn;
	}
	cout<<ans;
	return 0;
}
