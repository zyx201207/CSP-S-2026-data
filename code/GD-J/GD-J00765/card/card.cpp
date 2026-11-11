#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
const int M=3*1e5+10;
int a[N],ans[M];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(vis[a[j]]){
				for(int k=i;k<j;k++){
					if(a[k]==a[j]){
						for(int l=k;l<j;l++){
							vis[a[l]]=false;
						}
					}
					break;
				}
			}
			vis[a[j]]=true;
		}
		for(int i=1;i<=m;i++){
			if(vis[i])ans[i]++;
		}
		for(int i=1;i<=m;i++){
			vis[i]=false;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
