#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10,inf=1e15,md=1e9+7;
ll read(){
	ll ans=0,f=1;
	char s=' ';
	while(!(s>='0'&&s<='9')){
		s=getchar();
		if(s=='-')f=-1;
	}
	while(s>='0'&&s<='9'){
		ans=ans*10+s-'0';
		s=getchar();
	}
	return ans*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar('0'+x%10);
}
ll T,n,k,dd[N],rd[N],sum,llll;
vector<ll>e[N];
queue<ll>que;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read();T=read();
	while(T--){
		n=read();k=read();
		sum=dd[0]=n;llll=1;
		for(int i=1;i<=n;i++){
			e[i].clear();
			rd[i]=0;
		}
		for(int i=1;i<n;i++){
			ll u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
			rd[u]++;rd[v]++;
		}
		for(int i=1;i<=n;i++)
			if(rd[i]==1){
				que.push(i);
				sum--;
			}
		for(llll=1;!que.empty();llll++){
			dd[llll]=sum;
			ll sl=que.size();
			for(int i=1;i<=sl;i++){
				ll u=que.front();
				que.pop();
				for(auto v:e[u])if(rd[v]>1){
					rd[v]--;
					if(rd[v]==1){
						que.push(v);
						sum--;
					}
				}
			}
		}
		llll--;
		for(int i=0;i<=n;i++)
			if(dd[i]-dd[llll-i]<=k){
				write(i);
				putchar('\n');
				break;
			}
	}
	return 0;
}

