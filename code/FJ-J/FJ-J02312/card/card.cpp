#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500024],v[500024],a[500024],s[500024];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m;j++)s[j]=0;
		for(int j=i;j<=n;j++){
			if(s[a[j]]==0){
				sum++;
				v[sum]=a[j];
				s[a[j]]=sum;
			}else{
				for(int k=s[a[j]]+1;k<=sum;k++){
					s[v[k]]=0;
					v[k]=0;
				}
			}
		}for(int j=1;j<=sum;j++)ans[v[j]]++;
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

