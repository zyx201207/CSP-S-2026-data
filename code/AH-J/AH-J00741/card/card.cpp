#include<bits/stdc++.h>
using namespace std;
int n,m,s;
long long k=0,b[10000000],a[10000000],c[10000000]={0},nn;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	nn=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
	nn=n;
		for(int j=i;j<=n;j++){
			for(int ij=i;ij<=nn;ij++){
				if(b[ij]!=b[j]){
					k++;
				}
			}
			if(k==n-i){
				nn++;
				b[nn]=b[j];
			k=0;
			}
			else{
				nn=j;
				b[nn]=b[j];
				k=0;
				}
		}
		for(int j=i;j<=nn;j++){
			c[b[j]]++;
		}
	}
	s=1;
	while(s<=m){
		cout<<c[s]-1<<" ";
		s++;
	}
    return 0;
}
