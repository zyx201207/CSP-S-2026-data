#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
const int N=2e6+5;
const LL MX=2e18;
LL c,t,n,d,sum=0;
LL x[N];
bool flag[N];
vector<LL> vec;
void dfs(LL st,LL en,LL stop){
	if(vec.size()>=stop-1){
		vec.push_back(en);
		sort(vec.begin(),vec.end());
		for(LL i=1;i<vec.size();i++){
			if(x[vec[i]]-x[vec[i-1]]>d) return;
		}
		sum++;
		return;
	}
	for(LL i=st+1;i<en;i++){
		if(!flag[i]){
			vec.push_back(i);
			flag[i]=false;
			dfs(st,en,stop);
			flag[i]=true;
			vec.pop_back();	
		}		
	}
	return;
}
bool check(LL u,LL v){
	LL pos=u,cnt=0;
	while(pos<v){
		LL nxt=pos;
		while(nxt<=v&&x[nxt]-x[pos]<=d) nxt++;
		pos=nxt-1;
		cnt++;
	}
	sum=0;
	vec.clear();
	memset(flag,false,sizeof(flag));
	dfs(u,v,cnt);
	if(n==5) cout<<sum<<" "<<cnt<<endl;
	return (sum==2);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12){
		while(t--){
			memset(x,LL(0),sizeof(x));
			scanf("%lld%lld",&n,&d);
			LL ap,num,ans=0;		
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
			ap=x[n]-x[n-1];
			num=d/ap;
			if(num>=n||num<=1){
				cout<<0<<endl;
				continue;
			}
			ans=n-(2*num-1);
			cout<<ans<<endl;		
		}		
	}else{
		while(t--){
			memset(x,LL(0),sizeof(x));
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
			LL ans=0;
			for(LL i=1;i<=n-3;i++){
				for(LL j=i+3;j<=n;j++){
					if(check(i,j)) ans++;
				}
			}
			cout<<ans<<endl;
		} 
	}
	return 0;
}
