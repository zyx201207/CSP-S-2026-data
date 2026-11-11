#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500000],num[300000];
int main(){	
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long c[m+1];
		for(int j=n;j>=i;j--){
			if(c[a[j]] == 1){
				c[a[j+1]]=0;
			}
			else{
				c[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j]==1){
				num[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(num[i]>0){
			cout<<num[i]<<" ";
		}
	}
	return 0;
}
