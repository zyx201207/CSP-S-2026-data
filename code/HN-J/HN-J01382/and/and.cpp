#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int a[N],nu[N],m,n,ans=0;
bool f[31][N],vis[N];
string s,c;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int ti=a[i]; 
		while(ti){
			if(ti&1) s+='1';
			else s+='0';
			ti>>=1;
		}
		for(int j=1;j<=s.size();j++){
			int d=s[j-1]-'0';
			f[j][i]=d;
		}
		s=c;
	}
	memset(vis,true,sizeof(vis));
	for(int i=30;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(f[i][j]) nu[i]++;
		}
	}
	for(int i=30;i>=1;i--){
		if(nu[i]<m){
			continue;
		}
		ans=ans+(1<<(i-1));
		for(int j=1;j<=n;j++){
			if(f[i][j]==0&&vis[j]){
				for(int z=1;z<=30;z++)
					if(f[z][j]) nu[z]--;
				vis[j]=false;
			}
		}
	}
	cout<<ans;
	return 0;
}
