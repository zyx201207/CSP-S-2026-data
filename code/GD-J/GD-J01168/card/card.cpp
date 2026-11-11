#include<bits/stdc++.h>
using namespace std;
int n,m,nm,cm;
int main(){
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[n+1],c[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[100000],k=1;
		for(int j=i;j<=n;j++){
			b[k++]=a[j];
			for(int v=1;v<k-1;v++){
				if(b[k]==b[k-v]){
					nm=k-v;
					break;
				}
			}
			for(int v=nm;v<k-1;v++){
				b[v]=0;
			}
		}
		cm=k;
		for(int j=1;j<cm;j++){
			for(int v=1;v<=m;v++){
				if(b[j]==v){
					c[v]+=1;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
