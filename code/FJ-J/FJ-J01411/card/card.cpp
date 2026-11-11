#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050],ans[300030];
int it[500050];
int b[500010],z[300030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z[a[i]]=i;
		if(a[i]<a[i-1]) p=0;
	}
	if(p){
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
		}
		for(int i=m;i>=1;i--){
			ans[i]=ans[i+1]+ans[i];
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	int l;
	for(int i=1;i<=n;i++){
		l=0;
		memset(it,0,sizeof(it));
		for(int j=i;j<=n;j++){
			if(it[a[j]]==0){
				l++;
				it[a[j]]=l;
				b[l]=a[j];
			}
			else{
				for(int k=l;k>it[a[j]];k--){
					it[b[k]]=0;
				}
				l=it[a[j]];
			}
		}
		for(int j=1;j<=l;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
