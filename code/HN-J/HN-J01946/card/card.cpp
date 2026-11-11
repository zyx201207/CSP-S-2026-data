#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s[200005],sum[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				if(a[l]==a[j]) sum[i]=l;
			}
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			for(int z=sum[x]+x;z<=n;z++){
				if(a[z]==y) s[y]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i==1) cout<<s[i]+1<<" ";
		else cout<<s[i]<<" ";
	}
}
