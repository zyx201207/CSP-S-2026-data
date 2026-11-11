#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_pair(_first,_second) push_back(make_pair(_first,_second))
#define make_pair_of_three(_first,_second,_third) make_pair(make_pair(_first,_second),_third)
#define push_pair_of_three(_first,_second,_third) push_back(make_pair_of_three(_first,_second,_third))
#define F first
#define S second
#define st F.F
#define nd F.S
#define rd S
#define PII pair<int,int>
int c,n,m,d,q,fi,la,min1,min2;
int w[500005],k[505],a[500005],t[500005],ans[500005];
vector<PII > v[500005];
vector<pair<PII,int> >e;
bool f[500005];
pair<PII,int> *p;
void clean(){
	for(int i=1;i<=500000;i++) ans[i]=f[i]=0;
}
int fun(int x,int y){
	clean();
	e.clear();
	f[x]=1;
	for(int i=0;i<v[x].size();i++) e.push_pair_of_three(x,v[x][i].F,v[x][i].S);
	for(int i=1;i<=m;i++){
		min1=INT_MAX;
		for(int j=0;j<e.size();j++){
			if(min1>e[j].rd+ans[e[j].st]&&f[e[j].nd]==0){
				min1=e[j].rd+ans[e[j].st];
				min2=e[j].nd;
			}
		}
		if(min2==y) return min1;
		f[min2]=1;
		ans[min2]=min1;
		vector<pair<PII,int> >::iterator it;
		for(it=e.begin();it!=e.end();it++){
			if((*it).nd==min2){
				e.erase(it);
				break;
			}
		}
		for(int j=0;j<v[min2].size();j++) e.push_pair_of_three(min2,v[min2][j].F,v[min2][j].S);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++) scanf("%lld%lld",&a[j],&t[j]);
		for(int j=1;j<k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				v[a[j]].push_pair(a[l],t[j]+t[l]);
				v[a[l]].push_pair(a[j],t[j]+t[l]);
			}
		}
	}
	while(q--){
		scanf("%lld%lld",&fi,&la);
		printf("%lld\n",fun(fi,la)+w[fi]+w[la]);
	}
	return 0;
}
//100+50=150
//rp++
