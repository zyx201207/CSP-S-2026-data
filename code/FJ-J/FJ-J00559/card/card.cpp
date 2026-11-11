#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
long long n,m,nz[N],na[N],mz[M],x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nz[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i,jz=1;j<=n;j++,jz++){
			for(int k=1;k<=n-i;k++){
				if(na[k]==nz[j]){
					for(int l=k;l<=n;l++){
						na[l]=0;
					}
					jz=k;
				}
			}
			na[jz]=nz[j];
			x=jz;
		}
		for(int j=1;j<=x;j++){
			mz[na[j]]++;
			na[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mz[i]<<" ";
	}
	return 0;
}
