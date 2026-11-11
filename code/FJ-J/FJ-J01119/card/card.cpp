#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int op;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=i;l<j;l++){
				if(b[l]==a[j]){
					op=l;
					break;
				}
			}
			for(int k=op;k<j;k++){
				b[k]=0;
			}
			b[j]=a[j];
		}
		for(int j=1;j<=n;j++){
			if(b[j]!=0){
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
