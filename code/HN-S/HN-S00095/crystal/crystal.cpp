#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500010],maxs=LONG_MIN,mm;
struct sss{
	long long a,b;
};
sss dp(long long d,long long s,long long sc,long long i){
	if(d==n){
		sss ans;
		if(c[i]-c[d]<=sc){
			ans.a=1;
			return ans;
		}else{
			ans.a=0;
			return ans;
		}
	}
	long long num=0;
	if(c[d]-c[i]<=sc){
		sss dfs1=dp(d+1,s+1,sc-c[d]+c[i],i);
		sc=dfs1.b;
		num=dfs1.a+1;
	}
	num=max(num,dp(d+1,0,sc,d-1).a+1);
	cout<<num<<' '<<d<<endl;
	sss dfs;
	dfs.a=num,dfs.b=sc;
	return dfs;
}
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		maxs=max(c[i],maxs);
	}
	sort(c,c+n,cmp);
	cout<<dp(1,0,m,1).a;
	return 0;
}
