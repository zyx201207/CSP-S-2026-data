#include <bits/stdc++.h>
using namespace std;
const int MAXN=4e3+7;
int a[MAXN];
bool f[MAXN];
int s[MAXN];
long long ans[MAXN];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	bool fa=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1]) fa=false;
	}

	if(fa){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j>1&&a[j]==a[j-1]){
					continue;
				}
				if(a[j]==a[n]) maxx++;
				ans[a[j]]++;
			}
			
		}
		for(int j=2;j<=m;j++){
			cout<<ans[j]-1<<" ";
		}
		cout<<maxx;
		return 0;
	}	
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==true){
				for(int k=s[a[j]];k<=j;k++){
					f[a[k]]=false;
				}
			}
			s[a[j]]=j-i+1;
			f[a[j]]=true;
		}
		for(int j=1;j<=m;j++){
			if(f[j]==true){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

