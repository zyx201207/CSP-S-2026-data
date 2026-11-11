#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],cnt,z;
int main(){
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int l=1;l<=m;l++){
			b[l]=0;
		}
		cnt=0;
		for(int j=i;j<n;j++){
			b[cnt++]=a[j];
			z=a[j];
			for(int k=0;k<cnt-1;k++){
				if(b[k]==z){
					for(int l=k+1;l<=cnt;l++){
						b[l]=0;
					}
					cnt=k+1;
				}
			}
		}
		for(int k=0;k<m;k++){
			if(b[k]>0){
				c[b[k]-1]++;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
