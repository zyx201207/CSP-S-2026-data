#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
		(c=='-')?(f=-1):(f=f),c=getchar();
	while(isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}void write(int x){
	if(x<0)
		putchar('-'),x=-x;
	if(x<10)
		putchar(x+'0');
	else
		write(x/10),putchar(x%10+'0');
	return;
}int n,ans;
deque<ll>q;
ll m,sum,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		int num=q.size();
		if(a[i]*(num*1ll)>sum+m){
			while(!q.empty()){
				int cur=q.front();
				sum-=cur;
				q.pop_front();
				int curcnt=q.size();
				if(sum+m>=a[i]*(1ll*curcnt))
					break;
			}
		}ans=max(ans,(int)q.size()+1);
		q.push_back(a[i]),sum+=a[i];
	}write(ans);
	return 0;
}
