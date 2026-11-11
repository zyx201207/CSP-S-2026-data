#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int l=1;
	while(l<=n){
		bool vis[M]={false};
		for(int i=l;i<=n;i++){
			if(vis[a[i]]){
				for(int j=1;j<=m;j++){
					vis[j]=0;
				}
			}
			vis[a[i]]=1;
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				ans[i]++;
			}
		}
		l++;
    } 
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
