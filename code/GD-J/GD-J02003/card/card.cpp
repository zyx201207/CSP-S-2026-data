#include<bits/stdc++.h>
using namespace std;
int n,m,a[500008],b[300007],f[500008],f1[300008];
vector<int> ab[500008];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ab[a[i]].push_back(i);
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ab[a[j]].size()>=2){
				for(int k=0;k<ab[a[j]].size();k++){
					if(ab[a[j]][k]<=j){
						for(int o=ab[a[j]][0];o<ab[a[j]][k],o++)
							f[o]=1;
					}
				}
			}
		}for(int j=i;j<=n;j++){
			if(!f[j])
			    f1[a[j]]++;
		}
		for(int j=1;j<=n;j++){
			f[j]=0;
		}
	}for(int i=1;i<=m;i++){
		cout<<f1[i]<<' ';
	}
	return 0;
} 
