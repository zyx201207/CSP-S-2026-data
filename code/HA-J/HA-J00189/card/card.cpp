#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],ton[M],ton2[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ton[a[j]]==1){
				int k=j;
				while(k--){
					if(a[k]==a[j]) break;
					else ton[k]=0;
				}
			}else{
				ton[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(ton[j]==1) ton2[j]++;
			ton[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ton2[i]<<' ';
	}
	return 0;
}
