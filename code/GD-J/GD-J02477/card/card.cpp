#include<bits/stdc++.h>
using namespace std;
int a[500010];
int cnt[300010];
bool vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		vector<int> v;
		memset(vis,false,sizeof vis);
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				v.push_back(a[j]);
				vis[a[j]]=true;
			}else{
				while(v.size()){
					if(v.back()==a[j]) break;
					vis[v.back()]=false;
					v.pop_back();
				}
			}
		}
		for(auto x:v){
			cnt[x]++;
		}	
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}

