#include<iostream>
#include<cstring>
using namespace std;
long long a[10000009],n,m,v[10000009],ans[10000009],MX=-9999;
void dfs(long long STEP,long long begin){
	if(STEP>m){
		if(ans[STEP-1]>MX){
			MX=ans[STEP-1];
		}
	}
	for(long long i=begin;i<=n;++i){
		if(v[i]==false){
			v[i]=true;
			if(STEP==1) ans[STEP]=a[i];
			else ans[STEP]=ans[STEP-1]&a[i];
			dfs(STEP+1,i);
			v[i]=false;
		}
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(v,false,sizeof(v));
	scanf("%lld%lld",&n,&m);
	int MaX=-9999;
	for(long long i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(a[i]>MaX) MaX=a[i]; 
	}
	if(m==1){
		printf("%d",MaX);
		return 0;
	}
	for(long long i=1;i<=n;++i){
		dfs(1,1);
	}
	printf("%lld",MX);
	return 0;//freopen结束前注释要删掉！！！ 并保存！！！ 
}
