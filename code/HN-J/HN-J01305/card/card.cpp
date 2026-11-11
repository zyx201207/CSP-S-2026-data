#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[500000],sum[500000],b[50000];
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum[i]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			sum[a[j]]++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
