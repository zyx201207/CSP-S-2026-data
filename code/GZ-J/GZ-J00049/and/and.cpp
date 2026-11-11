//GZ-J00049 贵阳市第一中学 吴昊然 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool vis[N];
int n,m;
long long a[N],ans=2147483647;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=30;j>=0;j--){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if((a[i]>>j)&1==1){
				sum++;
			}
		}
		if(sum>=m){
			for(int i=1;i<=n;i++){
				if(vis[i])continue;
				if(!((a[i]>>j)&1==1)){
					vis[i]=1;
				}
			}
		} 
		if(sum==m){
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					ans&=a[i];
				}
			}
			cout<<ans;
			return 0;
		}
	}
	int xb=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		ans&=a[i];
		xb++;
		if(xb==m){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
