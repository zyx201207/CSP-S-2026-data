#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss,a[500005],pos[300005],d[500005],v[500005],ans[500005];
bool f[500005];
vector<lo> e[500005];
queue<lo> p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=n;i>=1;i--){
		if(pos[a[i]]){
			e[i].push_back(pos[a[i]]);
			d[pos[a[i]]]++;
			f[i]=false;
		}
		else{
			f[i]=true;
			e[i].push_back(i+1);
			d[i+1]++;
		}
		pos[a[i]]=i;
		v[i]=1;
	}
	for(i=1;i<=n;i++){
		if(!d[i])p.push(i);
	}
	while(!p.empty()){
		lo now=p.front();
		p.pop();
		if(f[now])ans[a[now]]=v[now];
		for(auto son:e[now]){
			d[son]--;
			v[son]+=v[now];
			if(!d[son])p.push(son);
		}
	}
	for(i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	
	return 0;
}

