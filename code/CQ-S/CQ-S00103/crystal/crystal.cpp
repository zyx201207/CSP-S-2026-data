#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],maxx=1,sum[500005],ans,t,p,l,w;
deque<long long> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	q.push_back(a[1]);
	for(long long i=2;i<=n;){
		ans=q.size();
		if(w+ans*(a[i]-a[i-1])<=m){
			w+=ans*(a[i]-a[i-1]);
			q.push_back(a[i]);
			ans=q.size();
			maxx=max(maxx,ans);
			i++;
		}else{
			w-=(a[i-1]-q.front());
			q.pop_front();
			ans=q.size();
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;
	return 0;
} 
