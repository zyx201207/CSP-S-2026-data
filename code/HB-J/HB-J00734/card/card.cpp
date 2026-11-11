
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sug=5e5+5;
int n,m;
int a[sug];
int tab[sug];
int ans[sug];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int len=0;
		memset(tab,0,sizeof(tab));
		for(int j=i;j<=n;j++){
			bool flag=1;
			for(int k=1;k<=len;k++){
				if(tab[k]==a[j]){
					len=k;
					flag=0;
					break;
				}
			}
			if(flag) tab[++len]=a[j];
		}
		for(int i=1;i<=len;i++){
			ans[tab[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
