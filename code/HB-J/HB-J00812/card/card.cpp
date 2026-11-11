#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[1111111];
long long b[1111111];
long long c[1111111];
int main(){
	//("card.in","r",stdin);
	//("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<=m;j++){
			c[i]=a[i];
			for(int k=0;k<j;k++){
				if(c[k]==c[j]){
					for(int y=k;y<j;y++){
						c[y]=0;
					}
					break;
				}
			}
		}
		for(int g=0;g<m+1;g++){
			b[(c[g])]++;
			cout<<i<<"c["<<g<<"]="<<c[g]<<' '<<"b["<<g<<"]="<<b[g]<<' ';
		}
		c[1111111]={};
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
