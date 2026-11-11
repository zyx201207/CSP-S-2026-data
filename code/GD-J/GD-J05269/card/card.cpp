#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000007],b[10000007],c[10000007],d[1000007];
long long tp=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				for(int k=c[a[j]];k<=n;k++){
					b[i]=0;
				}
				tp=1;
				b[a[j]]++;

			}
			else{
				tp++;
				b[a[j]]++;
				
			}
		}

		for(int l=1;l<=m;l++){

			if(b[l]!=0){
				d[l]++;
				
			}
		}

	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
