#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr LL N=5e5+10;
LL n,m,a[N],p1[N],p2[N],ans[N];
vector<LL> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]);
	for(LL i=1;i<=n;++i){
		//cout<<i<<endl;
		memset(p1,0,sizeof p1);
		memset(p2,0,sizeof p2);
		v.clear();
		for(LL j=i;j<=n;++j){
			if(p1[a[j]]){
				//cout<<p1[a[j]]<<','<<a[j]<<endl;
				LL x=p1[a[j]];
				if(!v.empty())for(LL k=p1[a[j]]+1;k<=(LL)v.size();++k)	p1[p2[k]]=0,p2[k]=0;
				if(!v.empty()&&x!=0)v.erase(v.begin()+x-1,v.end());
				v.push_back(a[j]);
				p1[a[j]]=x,p2[x]=a[j];
			}
			else{
				v.push_back(a[j]);
				p1[a[j]]=v.size();p2[v.size()]=a[j];
			}
			//for(auto x:v)	cout<<x<<' ';
			//puts("");
		}
		for(LL j=1;j<=m;++j)	ans[j]+=(p1[j]!=0);
	}
	for(LL i=1;i<=m;++i) printf("%lld ",ans[i]);
	return 0;
}
