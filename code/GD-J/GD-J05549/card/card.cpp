#include<bits/stdc++.h>
using namespace std;
int a[200005];
int flag[200005],ans[200005];
int ff[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//n¾Ö 
		for(int j=1;j<=m;j++){//Çå¿Õ 
			flag[j]=0;
		} 
		int t=i;
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==0){
				flag[a[j]]=j;
				t++;
			}else{
				for(int z=flag[a[j]];z<=t;z++){
					ff[z]=t-flag[a[j]];
				}
				t=flag[a[j]];
			}
		}
		for(int j=i;j<=t;j++){
			if(ff[j]==0)ans[a[j]]++;
			else ans[a[j]+ff[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
