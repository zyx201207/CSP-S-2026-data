#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n],b[n*2]={0},c[m]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long o=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(j!=0){
				for(int k=0;k<o;k++){
					if(b[k]==b[o]){
						for(int l=k;l<o;l++){
							b[k]=0;
						}
					}
				}
			}
			b[o]=a[j];
			o++;
		}
	}
	for(int i=0;i<o;i++){
		if(b[i]!=0){
			c[b[i]-1]++;
		}
	}
	for(int i=0;i<m;i++){
		if(i==0){
			cout<<c[i];
		}
		else{
			cout<<" "<<c[i];
		}
	}
	return 0;
}
