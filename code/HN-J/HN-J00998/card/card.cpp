#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],cnt[500010];
bool f[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)scanf("%d",b+i);
	for(int i=0;i<n;i++){
		memset(f,0,sizeof(f));
		for(int j=i;j<n;j++)a[j]=b[j];
		for(int j=i;j<n;j++)
			if(f[a[j]]){
				int k=j-1;
				while(a[j]!=a[k])cnt[a[k]]--,f[a[k]]=0,a[k]=0,k--;
				a[k]=0;
			}else cnt[a[j]]++,f[a[j]]=1;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
