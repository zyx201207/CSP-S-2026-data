#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],w[300005];
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(f[a[i]]==0){
				f[a[i]]=1;
			}
			else{
				memset(f,0,sizeof(f));
				f[a[i]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1)w[j]++;
		}
		memset(f,0,sizeof(f));
    }
	for(int j=1;j<=m;j++){
		cout<<w[j]<<" ";
	}
	return 0;
}



