#include <bits/stdc++.h> 
using namespace std; 
int n,m;
int a[500001]={};
int v[300001]={};
int num[500001]={};
int k=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			num[k]=a[j];
			for(int x=0;x<k;x++){
				if(num[x]==num[k]){
					k=x;
					break;
				}
			}
			k++;
		}
		for(int j=0;j<k;j++){
			v[num[j]]++;
		}
		k=0;
	}
	for(int i=1;i<=m;i++){
		if(v[i]>=1){
			cout<<v[i]<<" ";
		}
	}
	return 0;
}
