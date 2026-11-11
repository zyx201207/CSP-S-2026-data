#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool vis[200005];
int t[35];
int ans;
void funerase(int x){
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		if(a[i]&(1<<x)){
			continue;
		}
		vis[i]=1;
		for(int j=0;j<30;j++){
			if(a[i]&(1<<j)){
				t[j]--;
			}
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j)){
				t[j]++;
			}
		}
	}
	for(int i=30;i>=0;i--){
		if(t[i]>=m){
			ans|=(1<<i);
			funerase(i);
		}
	}
	printf("%d",ans);
	return 0;
}
