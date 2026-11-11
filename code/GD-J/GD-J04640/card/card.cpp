#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k[300005]={};
		for(int j=i;j<=n;j++){
			if(k[a[j]]==0){
				k[a[j]]=j;
			}else{
				for(int p=k[a[j]];p<j;p++){
					k[a[p]]=0;
				}
				k[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(k[j]!=0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
