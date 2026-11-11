#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int c,t;
int n;
long long d;
long long x[MAXN];
int ans;
vector<int> v;//step
vector<int> L;//cnt
int Top;
int cnt[MAXN];
int k[MAXN];
struct NodeP{
	pair<int,long long> a[MAXN];
	int l,r;
	void clear(){
		l=1;
		r=0;
	}
	void push(int x,long long b){
		r++;
		a[r]=make_pair(x,b);
	}
	void pop(){
		l++;
	}
	pair<int,long long> front(){
		return a[l];
	}
	int size(){
		return r-l+1;
	}
	bool empty(){
		return l==r+1;
	}
}q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		if(n>5000){
			if(n<=2){
				printf("0\n");
				continue;
			}
			scanf("%lld%lld",&x[1],&x[2]);
			for(int i=1;i<=n-2;i++)
				scanf("%lld",&x[3]);
			long long Ca=x[2]-x[1];
			if(Ca*2<=d&&d<Ca*3) printf("%d\n",n-3);
			else printf("0\n");
			continue;
		}
 		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		ans=0;
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof(cnt));
			int minx=0;
			v.clear();
			q.clear();
			q.push(i,1);
			cnt[0]=1;
			k[i]=0;
			for(int j=i+1;j<=n;j++){
				while(q.size()&&x[q.front().first]+d<x[j]){
					cnt[k[q.front().first]]-=q.front().second;
					q.pop();
				}
				if(q.empty()) break;
				while(cnt[minx]==0) minx++;
				cnt[minx+1]+=cnt[minx];
				k[j]=minx+1;
				q.push(j,cnt[minx]);
				if(cnt[minx]==2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
