#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int n,m,a[maxn],cnt;
struct node{
	int val,sum;
}p[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int ans=0,now=0,v=0,cur=0;
	for(int i=1;i<=n;i++){
		int j=i,sum=0;
		while(j<=n&&a[i]==a[j])
			sum++,j++;
		j--;
		p[++cnt]={a[i],sum};
		if(sum>ans)
			ans=sum;
		i=j;
	}
	now=p[1].sum,v=0,cur=p[1].val;
	deque<node>q;
	q.push_back(p[1]);
	for(int i=2;i<=cnt;i++){
		int del=p[i].val-cur;
		while(!q.empty()&&v+del*now>m&&now){
			node x=q.front();
			q.pop_front();
			if(v-(cur-x.val)*x.sum+(now-x.sum)*del<=m){
				int h=v+now*del-m,l=cur-x.val+del,p=min(x.sum,(h-1)/l+1);
				v-=p*(cur-x.val),now-=p;
				x.sum-=p;
				if(x.sum<=0)
					break;
				q.push_front(x);
			}
			else v-=(cur-x.val)*x.sum,now-=x.sum;
		}
		if(now<0)
			now=0;
		v+=now*del;
		q.push_back(p[i]);
		now+=p[i].sum;
		cur=p[i].val;
		ans=max(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}
// ni gan xiang xin wo yin wei `cur=p[1].val`->`cur=p[1].sum` tiao le 2h ma?
