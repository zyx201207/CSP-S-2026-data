#include<bits/stdc++.h>
using namespace std;
long long int n,k=1,m,sums=0,p;
long long int a[10010];
char b[10010],c[10010];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			k++;
			c[k]=b[i];
			m++;
		}
		}
		for(int i=1;i<=k/2;i++){
			if(c[i]!=c[m-i+1]){
					sums++;
			}
			}
			cout<<sums;
				return 0;
}
 
