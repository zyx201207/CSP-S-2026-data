#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo k,l,n,m,mm,r,s,ss,a[1000001],tt,number,dep[1000001],siz[1000001],d1,d2,v[51],fa[51],uu[51],vv[51],g[3];
vector<lo> e[1000001];
queue<lo> p;
bool t[51];
void bfs(){
	while(!p.empty()){
		lo now=p.front();
		p.pop();
		for(auto son:e[now]){
			if(dep[now]+1<dep[son])p.push(son),dep[son]=dep[now]+1;
		}
	}
}
lo father(lo x){
	if(x==fa[x])return x;
	return fa[x]=father(fa[x]);
}
void in(lo x,lo y){
	x=father(x),y=father(y);
	fa[x]=y;
}
int main(){
	lo i,j;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&number,&tt);
	while(tt--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<n;i++){
			scanf("%lld%lld",&l,&r);
			uu[i]=l,vv[i]=r;
			e[l].push_back(r);
			e[r].push_back(l);
		}
		if(m==n){
			printf("0\n");
			continue;
		}
		if(m==n-1){
			printf("1\n");
			continue;
		}
		if(m==n-2){
			printf("2\n");
			continue;
		} 
		mm=(1<<n)-1;
		ss=n;
		for(i=3;i<=mm;i++){
			k=0;
			for(j=1;j<=n;j++){
				fa[j]=j;
				if(i&(1<<j-1))k++,v[k]=j,t[j]=true;
				else t[k]=false;
			}
			if(k!=m)continue;
			for(j=1;j<=m;j++){
				if(t[uu[j]]&&t[vv[j]])in(uu[j],vv[j]);
			}
			r=0;
			for(j=1;j<=k;j++){
				if(!g[1])g[1]=father(v[j]);
				else if((!g[0])&&father(v[j])!=g[1])g[0]=father(v[j]);
				if(father(v[j])!=g[1]&&father(v[j])!=g[0]){
					r=1;
					break;
				}
			}
			if(r)continue;
			for(j=1;j<=n;j++){
				if(t[j])dep[j]=0;
				else dep[j]=1e17;
			}
			bfs();
			s=0;
			for(j=1;j<=n;j++)s=max(s,dep[j]),dep[j]=1e17;
			//cout<<i<<" "<<s<<"\n";
			ss=min(ss,s);
		}
		printf("%lld\n",ss);
	}
	
	return 0;
}

