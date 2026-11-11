#include<iostream>
using namespace std;
int n,m;
const int N=500000,M=300000;
int a[N],sum[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];	
	for(int i=1;i<=n;i++){
		int b[N];
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++)if(b[k]==a[j])for(int s=k;s<=j;s++)b[s]=0;
			b[j]=a[j];
		}
		for(int s=i;s<=n;s++)sum[b[s]]++;
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
/*
4 3
1 2 1 3
*/
	return 0;
}
