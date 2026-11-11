#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ls[300005],cs[300005];
bool b[300005],fla=1;
void dfs(int x){
	int fr=0;
	memset(b,0,m+5);
	memset(ls,0,m*8+5);
	for(int i=x;i<=n;i++){
		if(b[a[i]]){
			fr=ls[a[i]];
			for(int i=1;i<=m;i++){
				if(ls[i]>fr&&b[i]){
					cs[i]--;
					b[i]=0;
				}
			}
		}
		if(!b[a[i]])cs[a[i]]++;
		b[a[i]]=1;
		ls[a[i]]=++fr;
	}
}
signed main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])fla=0;
	}
	
	if(n<=500){
		for(int i=1;i<=n;i++){
			dfs(i);
		}
		for(int i=1;i<=m;i++){
			cout<<cs[i]<<' ';
		}
		return 0;
	}
	
	if(fla){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1])cout<<i<<' ';
		}
		return 0;
	}
	
	if(m==1){
		cout<<n;
		return 0;
	}
	
	if(m==2){
		for(int i=1;i<=n;i++){
			dfs(i);
		}
		for(int i=1;i<=m;i++){
			cout<<cs[i]<<' ';
		}
		return 0;
	}
	return 0;
}
