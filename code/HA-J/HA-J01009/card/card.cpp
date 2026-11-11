#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[300005];
int a[500005];
int p[300005],top=0;
ll n,m;
void dfs(ll x){
	int ff[300005]={};
	for(int i=x;i<=n;i++){
		p[++top]=a[i];
		ff[a[i]]++;
		if(ff[a[i]]==2){
			int topp=top;
			for(int j=1;j<=topp;j++){
				if(p[j]==a[i]){
					topp=j;
				}
			}
			for(int j=topp+1;j<=top;j++){
				ff[p[j]]--;
			}
			top=topp;
		}
	}
	for(int i=1;i<=top;i++){
		f[p[i]]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top=0;
		dfs(i);
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

