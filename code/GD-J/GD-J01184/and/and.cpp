#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ans=0;
struct node{
	int v;
	bool used;
}a[N];
void dfs(int x,int sum){
	if(x>m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i].used==0){
			if(x==1){
				sum=a[i].v;
			}
			else{
				sum=(sum&a[i].v);
			}
			a[i].used=1;
			dfs(x+1,sum);
			a[i].used=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].v);
		a[i].used=0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
