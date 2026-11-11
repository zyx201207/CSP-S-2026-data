#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],mi,mx,vis[N],ans[N];
bool pan[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mi,mx;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			pan[j]=1;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0&&pan[vis[a[j]]]){
				for(int k=vis[a[j]];k<j;k++){
					pan[k]=0;
				}
				vis[a[j]]=j;
			}else{
				vis[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(pan[j]){
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
} 
