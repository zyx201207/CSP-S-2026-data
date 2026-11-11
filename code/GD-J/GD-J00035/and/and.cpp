#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,vis[200005],vis2[200005];
vector<int> b[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=30;
		while(a[i]<(1<<x)){
			x--;
		}
		for(int j=x;j>=0;j--){
			if(a[i]>=1<<j){	
				b[j].push_back(i);
				a[i]-=(1<<j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
	}
	for(int i=30;i>=0;i--){
		memset(vis2,0,sizeof(vis2));
		int cnt=0;
		for(int j:b[i]){
			if(vis[j]){
				cnt++;
				vis2[j]=1;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				vis[j]&=vis2[j];
			}
			ans+=(1<<i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
