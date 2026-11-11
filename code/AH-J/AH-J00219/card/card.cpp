#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],f[500005],s[500005],card[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int w=1;
		memset(f,0,sizeof(f));
		memset(card,0,sizeof(card));
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				for(int u=f[a[j]]+1;u<=w;u++){
					f[card[u]]=0;
					card[u]=0;
				}
			}
			else{
				f[a[j]]=w;
				card[w++]=a[j];
			}
		}
		for(int i=1;i<=300005;i++){
			if(f[i]){
				s[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[a[i]]<<" ";
	}
	return 0;
}
