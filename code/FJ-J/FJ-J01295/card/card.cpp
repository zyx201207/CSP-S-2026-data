#include<bits/stdc++.h>
using namespace std;
int a[500005];
int o[500005];
int u[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=0;
	int l=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			k=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			u[l]=i;
			l++;
		}
	}
	if(k==0){
		for(int i=1;i<l;i++){
			cout<<u[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			int x;
			o[a[j]]++;
			for(int k=n;k>=j;k--){
				if(a[k]==a[j]){
					x=k;
					break;
				}
			}
			j=x+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<o[i]<<" ";
	}
	return 0;
} 
