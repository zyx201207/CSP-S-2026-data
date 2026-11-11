#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int id=1;
		for(int j=i;j<=n;j++){
			int x=0;
			for(int k=id;k>0;k--) if(s[k]==a[j]) x=k;
			if(x) id=x;
			s[id++]=a[j];
		}for(int j=1;j<=id;j++) ans[s[j]]++;
		fill(s+1,s+id+1,0);
	}for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
