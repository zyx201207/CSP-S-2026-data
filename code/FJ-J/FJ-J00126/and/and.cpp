#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	long long a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n-m+1;i++){
		long long s=a[i];
		for(int j=1;j<=m-1;j++){
			s&=a[i+j];
		}if(s>sum)sum=s;
	}cout<<sum;
	return 0;
}
