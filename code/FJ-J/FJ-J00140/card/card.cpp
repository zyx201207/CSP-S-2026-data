#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int cha;
		for(int j=0;j<n;j++){
			b[j]=a[j];
		}
		for(int j=i;j<n;j++){
			for(int k=i;k<j;k++){
				if(b[k]==b[j]){
					cha=j-k;
					for(int l=k+1;l<=j;l++){
						b[l]=b[l+cha];
						b[l+cha]=0;
					}
				}
			} 
		}
		int j=0;
		while(b[j]){
			cnt[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[m];
	}
	return 0;	
} 
