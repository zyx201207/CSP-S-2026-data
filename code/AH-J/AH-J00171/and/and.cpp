#include<bits/stdc++.h>
using namespace std;
int a[200100];
bool b[200100][32];
bool vis[200100];
int k[32];
void er(){
	k[0]=1;
	for(int i=1;i<=30;i++){
		k[i]=k[i-1]*2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	er();
	int n,m;
	cin>>n>>m;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		int l=1;
		while(x>0){
			len=max(len,l);
			b[i][l]+=x%2;
			x/=2;
			l++;
		}
	}
	int ans=0;
	for(int i=len;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				continue;
			}
			if(b[j][i]==1){
				cnt++;
			}
		}
		if(cnt<m){
			continue;
		}
		ans+=k[i-1];
		for(int j=1;j<=n;j++){
			if(vis[j]==1){
				continue;
			}
			if(b[j][i]==0){
				vis[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
