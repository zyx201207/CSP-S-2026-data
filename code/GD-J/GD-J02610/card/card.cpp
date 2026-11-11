#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000005],b[100000005],c[10005];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1+i;j<=n;j++){
			b[i]=a[i];
		}
		for(int j=1+i;j<=n;j++){
			for(int k=1;k<j;k++){
				if(b[j-k]=b[j]){
					for(int z=1;z<=k;z++){
						b[j-z]=0;
				}
				}
			}
		}
		for(int k=1;k<=m;k++){
		for(int j=1+i;j<=n;j++){
			if(b[j]==k){
				c[k]+=1;
			}
		}
	}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
