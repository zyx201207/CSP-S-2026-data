#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5]={0};
	long long b[n+5]={0};
	long long c[m+5]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=0;k<l;k++){
				if(b[k]==a[j]){
					for(int w=k+1;w<l;w++){
						b[w]=0;
					}
				}
				else{
					b[l]=a[j];
				}
			}
			l++;
		}
		for(int j=0;j<n;j++){
			if(b[j]!=0){
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
}
