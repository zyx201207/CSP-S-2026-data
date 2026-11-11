#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
long long a[maxn],las[maxn],ans[maxn],r[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int z = 1;
		memset(las,0,sizeof(las));
		for(int j = i;j<=n;j++){
			if(las[a[j]]>0){
				for(int k = las[a[j]]+1;k<z;k++){
					las[r[k]] = 0;
				}
				z = las[a[j]];
			}
			r[z] = a[j];
			las[a[j]] = z;
			z++;
		}
		for(int j = 1;j<z;j++){
			ans[r[j]]++;
//			cout<<r[j]<<" ";
		}
//		cout<<"\n";
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
