#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],book[500005],book2[500005],cf[500005],ans[500005];
int z=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(book2,0,sizeof book2);
		memset(book,0,sizeof book);
		memset(cf,0,sizeof cf);
		for(int j=i;j<=n;j++){
			if(book[a[j]]==0 || cf[book[a[j]]]!=0){
				book[a[j]]=j;
			}
			else{
				for(int k=book[a[j]];k<j;k++) cf[k]=1;
				book[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(cf[j]==0){
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
