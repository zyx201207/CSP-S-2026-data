#include<bits/stdc++.h>
using namespace std;
int a[200005],sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		for(int j=i+1;j<=n-m+2;j++){
			int y=a[i];
			for(int k=0;k<m-1;k++){
				y&=a[j+k];
			}
			sum=max(y,sum);
		}
	}
	cout<<sum;
	return 0;
} 
