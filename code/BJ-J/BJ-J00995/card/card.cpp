#include<bits/stdc++.h>
using namespace std;
long long n,m,id[500005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			id[a[j]]+=1;
			long long p=j+1;
			while(p<=n&&a[p]!=a[j]){
				p+=1;
			}
			if(a[j]==a[p]){
				id[a[j]]-=1;
				j=p-1;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<id[i]<<" ";
	}
	return 0;
}
