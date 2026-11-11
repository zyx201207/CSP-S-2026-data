#include <bits/stdc++.h>
using namespace std;
int n,m,le;
long long a[200001],b[200001],maxn;
int check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if((a[i]>>x)&1==1){
			cnt++;
		}
	}
	return cnt;
}
void dfs(int i,int u,long long xx){
	if(u==m){
		maxn=max(maxn,xx);
		return ;
	}
	if(i==le+1){
		return ; 
	}
	dfs(i+1,u+1,xx&b[i]);
	dfs(i+1,u,xx);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=0,r=30,ans,ge;
	while(l<=r){
		int mid=(l+r)/2;
		int t=check(mid);
		if(t>=m){
			l=mid+1;
			ans=mid;
			ge=t;
		}else{
			r=mid-1;
		}
	}
	long long aans=((((1<<30)-1)<<1)+1);
	if(ge==m){
		for(int i=1;i<=n;i++){
			if((a[i]>>ans)&1==1){
				aans&=a[i];
			}
		}
		cout<<aans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if((a[i]>>ans)&1==1){
			b[++le]=a[i];
		}
	}
	dfs(1,0,((((1<<30)-1)<<1)+1));
	cout<<maxn;
	return 0;
}
