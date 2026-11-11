#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],b[M],c[M],flag[M],g[M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		memset(g,0,sizeof g);
		memset(flag,0,sizeof flag);
		for(int j=i;j<=n;j++){
			if(flag[a[j]]){
				for(int k=flag[a[j]];k<j;k++){
					g[a[k]]--;
				}
			}
			flag[a[j]]=j;
			g[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			if(g[j]){
				c[j]+=1;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
