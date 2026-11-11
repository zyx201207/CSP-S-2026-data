#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N]={},ans=0;
map<int,int> mp;
map<int,bool> flag;

void dfs(int stp,int now,int d){
	if(stp>=m){
		ans=max(ans,now);
		return;
	}
	for(int i=d+1;i<=n;i++){
		if(!flag[a[i]]){
			flag[a[i]]=1;
			dfs(stp+mp[a[i]],a[i]&now,i);
			flag[a[i]]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		flag[a[i]]=1;
		dfs(mp[a[i]],a[i],i);
		flag[a[i]]=0;
	}
	cout<<ans;
	printf("\n");
	return 0;
}

