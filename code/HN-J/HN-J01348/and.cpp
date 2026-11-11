#include<bits/stdc++.h>
using namespace std;
int const N=1e7+10;
int a[N],b[N];
int main(){
	fleopen("and.in","r",stdin);
	fleopen("and.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(b[j]<a[i]){
				b[j]=a[i];
				x=i;
			}
		}
		a[x]=0;
	}
	for(int j=1;j<=m;j++){
		cout<<b[m];
		return 0;
	}
	return 0;
} 
