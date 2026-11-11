#include<bits/stdc++.h>
using namespace std;
int c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10],b[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=n-i+1;
		for(int j=1;j<=l;j++){
			b[j]=a[j+i-1];
		}
		for(int j=i;j<=n;j++){
			for(int k=1;k<=l;k++){
				if(b[k]==a[j]){
					l=k-1;
					break;
				}
			}
			l++;
			b[l]=a[j];			
		}
		for(int j=1;j<=l;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
