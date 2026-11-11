//GZ-J00135 观山湖区外国语实验中学（南校区） 安辉煌
#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000],cnt[500050],b[500050],d[500050],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	for(int i=1;i<=n;i++){
		int z[500050]={};
		for(int j=i;j<=n;j++){
			if(b[z[d[t]]]==1){
				a[j]=d[t];
			}
			z[j]=a[j];
			b[z[j]]=1;
			d[t]=j;
			t++;
		}
		cnt[z[i]]++;	
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
