#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200020],cnt[300020],id=1,tab[200020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		for(int i=1;i<=n;i++){
			tab[i]=a[i];
		}
		for(int i=t;i<=n;i++){
			for(int j=t;j<=n;j++){
				if(tab[j]==a[i]){
					id=j;
					for(int k=j;k<=n;k++){
						tab[k]=0;
					}
					break;
				}
			}
			tab[id]=a[i];
			id++;
		}
		for(int i=t;i<=n;i++){
			if(tab[i]!=0){
				cnt[tab[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
	return 0;
}