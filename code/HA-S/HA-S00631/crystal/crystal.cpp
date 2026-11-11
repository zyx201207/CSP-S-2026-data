#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],sum,l,r,mid,rr,ans,cnt;
priority_queue<long long,vector<long long>,greater<long long> >q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(a[i]*cnt-sum>m){
			sum-=q.top();
			cnt--;
			q.pop();
		}
		ans=max(ans,cnt+1);
		q.push(a[i]);
		cnt++;
		sum+=a[i];
	} 
	cout<<ans;
	return 0;
}
