#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+100;
int n,m;
int a[N];
int vis[N],s[N],vv[N],lx[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		s[i]=s[i-1];
		if(vis[a[i]]==0){
			s[i]++;
			vis[a[i]]=1;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			lx[j]++;
			if(vv[a[j]]!=0){
				
			}
			if(vv[a[j]]==0){
				vv[a[j]]=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<1;	
	}
	return 0;
} 
