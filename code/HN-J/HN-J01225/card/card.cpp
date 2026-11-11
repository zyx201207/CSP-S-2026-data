#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long x[500005]={},p=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=p;k++){
				if(x[k]==a[j]){
					p=k-1;
					break;
				}
			}
			x[++p]=a[j];
		}
		for(int j=1;j<=p;j++){
			t[x[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
