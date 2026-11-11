#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,sum=0,ans=0;
queue<pair<long long,char>> c;
stack<pair<long long,char>> d;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	vector<long long> a(n+1,0);
	vector<char> b(n+1,0);
	for(long long i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&b[i]);
		cnt+=a[i];
	}
	long long i;
	bool sc=true;
	for(i=1;i<=n;i++){
		if(sc&&sum+a[i]>cnt/2) c.push({cnt/2-sum,b[i]}),d.push({sum+a[i]-(cnt+1)/2,b[i]}),sc=false;
		sum+=a[i];
		if(sc) c.push({a[i],b[i]});
		else d.push({a[i],b[i]});
	}
	while((!c.empty())&&(!d.empty())){
		bool sc=true;
		long long num=0;
		if(c.front().second==d.top().second) sc=false;
		if(c.front().first>d.top().first) c.front().first-=d.top().first,num=d.top().first,d.pop();
		else if(c.front().first<d.top().first) d.top().first-=c.front().first,num=c.front().first,c.pop();
		else num=c.front().first,c.pop(),d.pop();
		if(sc) ans+=num;
	}
	printf("%lld",ans);
} 
