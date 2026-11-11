#include<bits/stdc++.h>
using namespace std;
bool st[200005];
int n,m;
int a[200005],_max=-1;
void dfs(int x,int ans,int number){
	st[x]=1;
	//cout<<x<<" "<<ans<<endl;
	if(number==m){
		ans=ans&a[x];
	//	cout<<ans<<" ";
		_max=max(_max,ans);
	}else{
		if(x==n){
			return;
		}
		for(int i=1;i<=n;i++){
			if(st[i]==0){
				st[i]=1;
				dfs(i,ans&a[x],number+1);
				st[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	st[1]=1;
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1);
	}
	cout<<_max;
	return 0;
}
