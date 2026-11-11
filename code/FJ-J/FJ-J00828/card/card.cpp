#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
long long x[400000],x1[400000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int c=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=c;k++){
				if(x1[k]==a[j]){
					c=k-1;
				}
			}
			c++;
			x1[c]=a[j];
		}
		for(int i=1;i<=c;i++){
			x[x1[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<" ";
	}
	return 0;
} 
