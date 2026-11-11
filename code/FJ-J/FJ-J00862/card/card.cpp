#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[5000050],b[5000050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int y[5000050]={};
		int d[5000050]={};
		int sum=1,x=i;
		while(x<=n){
			y[sum]=a[x];
			if(d[y[sum]]==0||d[y[sum]]>sum){
				d[y[sum]]=sum;
			}else{
				sum=d[y[sum]];
			}
			sum++;
			x++; 
		}
		for(int j=1;j<=sum;j++){
			b[y[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << b[i] <<" ";
	}
	return 0;
}
