#include<bits/stdc++.h>
using namespace std;
const int N=1047575;
int n,m,a[200010],ans;
bool vis[200010];
/*int nuon(int a){
	int x=0;
	while(a){
		a>>1;
		x++;
	}
	return nuon;
}*/
bool cmp(int a,int b){
	return a>b;
}
int dfs(int step,int num,int idx){
	if(step>m)return num;
	vis[idx]=1;
	int id=0,Ma=-1;
	for(int i=1;i<=n;++i){
		if(num&a[i]>Ma&&(!vis[i])){
			Ma=num&a[i];
			id=i;
			cout<<Ma<<' '<<id<<endl;
		}
	}
	int abcd=dfs(step+1,Ma,id);
	vis[idx]=0;
	return abcd;
}
int main(){
	reopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	/*for(int i=1;i<=n-m;++i){
		ans=max(ans,dfs(1,a[i],i));
	}*/
	cout<<dfs(1,a[1],1);
	return 0;
}
