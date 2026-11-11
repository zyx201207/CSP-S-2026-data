#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+5;
ll n,m,a[MAXN],s[MAXN],sum;
int ans,len;
deque<ll> q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(q.empty())
			q.push_back(a[i]),len++;
		else{
			sum=sum+q.size()*(a[i]-q.back());
			while(!q.empty()&&sum>m){
				sum=sum-(a[i]-q.front());
				q.pop_front();
				len--;
			}
			q.push_back(a[i]);
			len++;
		}
		ans=max(ans,len);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

4 3
1 10 11 12
*/
