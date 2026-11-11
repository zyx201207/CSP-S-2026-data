#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[100005];
int b[100005],t;
int o[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int i=1;i<=n+1;i++){
			b[i]=0;
		}t=0;
		for(int j=n-i+1;j<=n;j++){
			b[t++]=a[j];
			for(int k=t-1;k>=1;k--){
				if(b[k]==a[j]){
					//cout<<7891;
					for(int l=k+1;l<=t;l++){
						b[l]=0;
					}
					t=k+1;
					//for(int j=1;j<=t;j++){
			//cout<<b[j]<<' ';
			//o[b[j]]++;
		}
					break;
				}
			}
		}	
		for(int j=1;j<=t;j++){
			//cout<<b[j]<<' ';
			o[b[j]]++;
		}
		//c/out<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<o[i]<<' ';
	}
	return 0;
}

