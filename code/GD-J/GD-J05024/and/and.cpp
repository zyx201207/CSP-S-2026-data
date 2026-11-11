#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long n,m,a[N],ans=0;
long long maxn=-1,ands;
bool b[N],allA=1;
struct node{
	int num,x;
};
node c[N];
void dfs(int x){
	if(x>=n+1){
		long long k=-1,cnt=0;
		bool f=0;
		for(int i=1;i<=n;i++) if(b[i]) cnt++;
		if(cnt!=m) return;
		for(int i=1;i<=n;i++){
			if(!f&&b[i]){
				k=a[i];
				f=1;
			}
			else if(b[i]){
				k=k&a[i];
			}
		}
		ans=max(ans,k);
		return;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=0;
	dfs(x+1);
}
int many(long long x){
	int ans=0;
	while(x>0){
		if(x%2==1) ans++;
		x/=2;
	}
	return ans;
}
bool cmp(node a,node b){
	if(a.num!=b.num) return a.num>b.num;
	else return (a.x>b.x);
}
bool cmp2(int a,int b){
	return (many(a)>many(b));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		if(many(a[i]+1)!=1) allA=0; 
	}
	if(n<=20){
		//1-5[25]
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==1){
		//6[5]
		cout<<maxn;
		return 0;
	}
	if(m==n){
		//7[5]
		ands=a[1];
		for(int i=2;i<=n;i++){
			ands=ands&a[i];
		}
		cout<<ands;
		return 0;
	}
	if(m==2){
		//8-10[15]
		maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				maxn=max(maxn,x);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(allA){
		//13[5]
		sort(a+1,a+1+n,cmp2);
		ands=a[1];
		for(int i=2;i<=m;i++){
			ands=ands&a[i];
		}
		cout<<ands;
		return 0;
	}
	//11-12,14-20[may be 10]
	for(int i=1;i<=n;i++){
		c[i].num=many(a[i]);
		c[i].x=a[i];
	}
	sort(c+1,c+1+n,cmp);
	ands=c[1].x;
	for(int i=2;i<=m;i++) ands=ands&c[i].x;
	cout<<ands;
	return 0;
}
