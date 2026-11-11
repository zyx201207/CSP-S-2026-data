#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m,sum=0,sum1=-1;
	cin>>n,m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int z=1;z<=m;z++){
				if(a[i]+j==a[z]){
					sum++;
				}
			}
		}
		
		if(sum1<=sum){
			sum1=sum;
		}
	}
	cout<<sum1+1;
	return 0;
}
