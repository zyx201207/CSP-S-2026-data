#include<bits/stdc++.h>
using namespace std;
int n,m;
bool visit[200005];
long long a[200005],ans;
void dfs(int c,long long andd){
	if(c==0){
		ans=max(ans,andd);
//		cout<<andd<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(visit[i]==false){
			visit[i]=true;
			if(c==m) dfs(c-1,a[i]);
			else dfs(c-1,andd&a[i]);
			visit[i]=false;
		}
	}
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	cin>>n>>m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
//		cin>>a[i];
		scanf("%lld",&a[i]);
	}
	if(n<=20){
		dfs(m,0);
	}else{
		sort(a+1,a+n+1,cmp);
		if(m==1){
			ans=a[1];
		}else if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans=ans&a[i];
			}
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j) ans=max(ans,a[i]&a[j]);
				}
			} 
		}else{
			ans=a[m];
		} 
	}
	cout<<ans;
	printf("%lld",ans);
}
/*
做不出满分，那就骗分
1-5暴力
6选最大
8-10选相同的两个 
13排序，选前m个
4 2
3 15 12 12
4 2
7 3 1 31
*/
