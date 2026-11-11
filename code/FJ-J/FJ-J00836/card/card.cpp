#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >>m ;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
		}
		for(int l=1;l<=n;l++){
		int num=l; 
		for(int j=l+1;j<=n;j++){
			if(b[j]==b[num]){
				for(int k=l;k<j;k++){
					b[k]=0;
				}
				num=j;
			}
		}}
		for(int j=i;j<=n;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
