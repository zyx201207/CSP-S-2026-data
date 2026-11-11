#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int> a;
bool vis[200007];
void dg(int sum,int cnt){
	if(sum==m){
		ans=max(ans,cnt);
		return ;
	}
	else{
		for(int i=0;i<n;i++){
			if(!vis[i]){
				vis[i]=1;
				dg(sum+1,int(cnt & a[i]));
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int sum;
		scanf("%d",&sum);
		a.push_back(sum);
	}
	vis[0]=1;
	dg(1,a[0]);
	printf("%d",ans);
	return 0;
}
