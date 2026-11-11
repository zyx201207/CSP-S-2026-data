#include<bits/stdc++.h>
using namespace std;
int a[1001001],cnt[1001001],ines[1001001],e[1001001],f[1001001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])flag=1;
	}if(flag==0){
		int t=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cnt[a[i]]=i;
			}
		}for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}return 0;
	}
	for(int j=1;j<=n;j++){
		if(f[a[j]]!=0){
			int k=f[a[j]];
			e[j]=k;
		}
		f[a[j]]=j;
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(e[j]==0||e[j]<i)continue;
			if(ines[e[j]]==1)continue;
			for(int ee=e[j];ee<j;ee++)ines[ee]=1;
		}for(int j=i;j<=n;j++){
			if(ines[j]==0)cnt[a[j]]++;
		}memset(ines,0,sizeof(ines));
	}for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
