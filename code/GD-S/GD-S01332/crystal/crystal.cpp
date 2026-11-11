#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll n,a[N],sum,m;
priority_queue<ll> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=n;i>=1;i--){
		if(q.empty()){
			if(a[i]<=m) q.push(a[i]);
			continue;
		}
		int k=q.top();
		if(k-a[i]+sum<=m){
			q.push(a[i]);
			sum+=(k-a[i]);
		}else{
			q.pop();int u=q.top();
			int sum1=sum-(k-u)*q.size()+u-a[i];
			if(sum1<=m){
				q.push(a[i]);
				sum=sum1;
			}else q.push(k);
		}
	}
	cout<<q.size();
	return 0; 
}
