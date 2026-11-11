#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int n,m,now,cost;
int ans=1,mn=1e18;
queue<int> q;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+1ll*(ch-48),ch=getchar();
	return x*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),mn=min(mn,a[i]);
	mn=abs(mn);
	for(int i=1;i<=n;i++)a[i]+=mn;
	sort(a+1,a+n+1);
	q.push(1);
	now++;
	for(int i=2;i<=n;i++){
		cost+=(a[i]-a[i-1])*now;
		q.push(i);
		now++;
		while(cost>m){
			now--,cost-=a[i]-a[q.front()];
			q.pop();
		}
		ans=max(ans,now);
	}
	printf("%lld\n",ans);
}
