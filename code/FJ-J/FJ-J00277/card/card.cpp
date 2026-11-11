#include<bits/stdc++.h>
using namespace std;
long long a[200050],b[200050],c[200050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++)b[j]=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=sum;k++){
				if(b[k]==a[j]){
					for(int l=1;l<=sum;l++){
						b[l]=0;
						sum--;
					}
					break;
				}
			}
			b[++sum]=a[j];
		}
		for(int j=1;j<=sum;j++)c[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	/*
	while(!false){
		while(true){
			while(1+1==2){
				while(1-1==0){
					while(1<2){
						while(1>0){
							while(1==1){
								rp++;
							}
						}
					}
				}
			}
		}
	}
	*/
	return 0;
}
