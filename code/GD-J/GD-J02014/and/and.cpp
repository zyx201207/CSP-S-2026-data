#include<bits/stdc++.h>
using namespace std;
int sb(int x){//数1的个数
	int x_n=0;
	while(x>0){
		x_n+=x%2;
		x/=2;
	}
	return x_n;
}
int n,m;
int a[20005],gs[2005][20005],gs2[20005];
int b[2005][20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int temp=sb(a[i]);
		gs2[i]=temp;
		if(temp>=gs[1][i-1]){
			gs[1][i]=temp;
			b[1][i]=a[i];
		}else{
			gs[1][i]=gs[1][i-1];
			b[1][i]=b[1][i-1];			
		}
	}
	for(int i=2;i<=m;i++){
		int sum1=a[1];
		for(int j=2;j<=i;j++){
			sum1=int(sum1&a[i]);
		}
		b[i][i]=sum1;
		gs[i][i]=sb(sum1);
	}
	for(int i=2;i<=m;i++){//选i个
		for(int j=n;j>=i+1;j--){//有j个
			int sum=int(a[j]&b[i-1][j]);
			int gs1=gs2[i];
			if(gs1>gs[i][j-1]){
				gs[i][j]=gs1;
				b[i][j]=sum;
			}else{
				gs[i][j]=gs[i][j-1];
				b[i][j]=b[i][j-1];
			}
		}
	}
	cout<<b[m][n];
}
/*
5 3
31 3 1 15 7
*/
