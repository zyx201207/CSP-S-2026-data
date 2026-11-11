#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
priority_queue<long long,vector<long long>,greater<long long> >q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&arr[i]);
	sort(arr+1,arr+1+n);
	q.push(arr[1]);
	long long now=arr[1],sum=0;
	int ans=1,eans=0;
	for(int i=2;i<=n;i++){
		sum+=(arr[i]-now)*ans;
		ans++;
		q.push(arr[i]);
		now=arr[i];
		while(!q.empty()&&sum>m){
			sum-=now-q.top();
			q.pop();
			ans--;
		}
		eans=max(ans,eans);
	}
	printf("%d",eans);
	return 0;
}
