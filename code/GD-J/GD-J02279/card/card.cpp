#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k[n+10]={};
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	int ans[m+10]={};
	for(int i=1;i<=n;i++){
		int ga[n+10]={};
		for(int j=i;j<=n;j++){
			if(j==i){
				ga[j]=k[j];
			}
			int gh=0;
			for(int l=i;l<j;l++){
				if(gh==1){
					ga[l]=0;
					continue;
				}
				if(ga[j]==ga[l]){
					gh=1;
				}
			}
		}
		int an[m+10]={};
		for(int j=i;j<=n;j++){
			an[ga[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=an[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
