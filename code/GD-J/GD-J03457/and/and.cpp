#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a,path;
long long res=0;
void dfs(int chs,long long s,int st){
	if(chs==m){
		res=max(res,s);
		return;
	}
	if(st>n)return;
	for(int i=st;i<=n;i++){
		path.push_back(a[i]);
		if(chs==0)dfs(chs+1,a[i],i+1);
		else dfs(chs+1,s&a[i],i+1);
		path.pop_back();
	}
	dfs(chs,s,st+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		printf("%d",*max_element(a.begin()+1,a.end()));
		return 0;
	}
	if(m==n){
		res=a[1];
		for(int i=2;i<=n;i++){
			res&=a[i];
		}
		printf("%lld",res);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				res=max(res,(long long)(a[i]&a[j]));
			}
		}
		printf("%lld",res);
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			long long sum=0;
			bool first=1;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(first){
					first=0;
					sum=a[j];
				}
				else sum&=a[j];
			}
			res=max(sum,res);
		}
		printf("%lld",res);
		return 0;
	}
	dfs(0,0,1);
	printf("%lld",res);
	return 0;
}
