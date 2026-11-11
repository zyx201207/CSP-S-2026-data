#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
long long b1[500005];
int main(){
	freopen("card.in",r,stdin);
	freopen("card.out",w,stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=j;
			}
			else{
				for(int l=1;l<=m;l++){
					if(b[l]>b[a[j]])b[l]=0;
				}
			}
		}
		for(int l=1;l<=m;l++){
			if(b[l]>0)b1[l]++;
			b[l]=0;
		}
	}
	for(int l=1;l<=m;l++){
		cout<<b1[l]<<' ';
	}
	return 0;
}
