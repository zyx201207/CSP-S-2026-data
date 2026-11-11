#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int ci[N];
int nex[N],vis[N];
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			nex[j]=0;
		}
		for(int j=1;j<=n;j++){
			vis[j]=1;
		}
		for(int j=i;j<=n;j++){
			ci[a[j]]++;
			if(nex[a[j]]){
				for(int k=nex[a[j]];k<j;k++){
					if(vis[k]){
						ci[a[k]]--;
						nex[a[j]]=0;
						vis[k]=0;
					}
				}
				nex[a[j]]=j;
			}
			else nex[a[j]]=j;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ci[i]<<" ";
	}
	return 0;
}
