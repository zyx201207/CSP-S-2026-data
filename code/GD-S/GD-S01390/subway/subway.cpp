#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans,tx[502][502],pq[502],qp[505],s[500005];
struct node{
	vector<long long> head,len;
};
node a[500005],t[500005];
bool amax(long long x,long long y){
	if(x>y||x==0) return true;
	else return false;
}
void f(long long p,long long l){
	if(amax(pq[p],l)&&amax(ans,l)){
		pq[p]=l;
		if(qp[p]>0&&amax(ans,qp[p]+l)){
			ans=l+qp[p];
		}
		long long j;
		for(j=1;j<=t[p].head[0];j++){
			f(t[p].head[j],t[p].len[j]+l);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	long long i,j,k,l,v;
	for(i=1;i<=m;i++){
		scanf("%lld",&s[i]);
		a[i].head.push_back(0);
		a[i].len.push_back(0);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&j);
		while(j>0){
			j--;
			scanf("%lld%lld",&k,&l);
			a[k].head[0]++;
			a[k].head.push_back(i);
			a[k].len.push_back(l);
			for(v=1;v<a[k].head[0];v++){
				if(amax(tx[i][a[k].head[v]],l+a[k].len[v])){
					tx[i][a[k].head[v]]=l+a[k].len[v];
					tx[a[k].head[v]][i]=l+a[k].len[v];
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		t[i].head.push_back(0);
		t[i].len.push_back(0);
		for(j=1;j<=n;j++){
			if(tx[i][j]>0){
				t[i].head[0]++;
				t[i].head.push_back(j);
				t[i].len.push_back(tx[i][j]);
			}
		}
	}
	for(i=1;i<=q;i++){
		ans=0;
		scanf("%lld%lld",&l,&v);
		for(j=1;j<=n;j++){
			pq[j]=0;
			qp[j]=0;
		}
		for(j=1;j<=a[v].head[0];j++) qp[a[v].head[j]]=a[v].len[j];
		for(j=1;j<=a[l].head[0];j++){
			f(a[l].head[j],a[l].len[j]);
		}
		printf("%lld\n",ans+s[l]+s[v]);
	}
	return 0;
}
