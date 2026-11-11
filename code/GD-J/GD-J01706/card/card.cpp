#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],b[1000001]={0},s[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int k=i;k<=j;k++){
				if(b[k]==a[j]){
					for(int l=k+1;l<=n;l++){
						b[l]=0;
					}
				}
			}
		}
		for(int k=i;k<=n;k++){
			if(b[k]!=0){
				s[b[k]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
