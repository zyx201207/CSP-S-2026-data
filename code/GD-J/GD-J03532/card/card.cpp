#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int f[n+1];
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++){		
			for(int k=j-1;k>=i;k--){
				if(f[k]==0&&a[j]==a[k]){
					f[k]++;
					f[j]--;
				}
			}
		}int k[m+1]={0};
		for(int j=i;j<=n;j++){
			f[j]=f[j-1]+f[j];
			if(f[j]==0)k[a[j]]=1;
		}for(int j=1;j<=m;j++)b[j]+=k[j];
	}for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
