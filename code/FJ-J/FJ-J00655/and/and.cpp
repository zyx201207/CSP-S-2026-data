#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],vis[200010],ans;
int mp[200010][50];
void f(int x,int p){
	int ind=0;
	while(x!=0){
		mp[p][++ind]=x%2;
		x/=2;
	}return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f(a[i],i);
	}for(int i=31;i>=1;i--){
		int c=0;
		for(int j=1;j<=n;j++) if(vis[j]==0 && mp[j][i]) c++;
		if(c>=m){
			for(int j=1;j<=n;j++) if(mp[j][i]==0) vis[j]=1;
			if(c==m) break;
		}
	}for(int i=1;i<=n;i++){
		if(vis[i]==0 && ans==0) ans=a[i];
		else if(vis[i]==0) ans=ans&a[i];
	}cout<<ans;
	return 0;
} 
