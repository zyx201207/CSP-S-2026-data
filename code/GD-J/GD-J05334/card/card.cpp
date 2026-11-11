#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N],n,m,cnt[N];
void play(int x){
	bool vis[N];
	bool f[N];
	memset(f,0,sizeof(f));
	memset(vis,false,sizeof(vis));
	for(int i=x;i<=n;i++){
		cnt[a[i]]++;
		if(vis[a[i]]==true){
			for(int j=i-1;j>=x;j--){
				if(vis[a[i]]==1){
					
					if(f[j]!=1){
						cnt[a[j]]--;
					}
					vis[a[j]]=false;
					f[j]=1;
				}
			}
		}
		vis[a[i]]=true;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(cnt,0,sizeof(cnt));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		play(i);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
		if(i!=m) cout<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
