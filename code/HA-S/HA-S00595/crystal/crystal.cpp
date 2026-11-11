#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ma=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<=m;i++){
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				int sum=0;
				for(int l=j;l<=k;l++){
					sum+=a[k]-a[l];
				}
				if(sum<=i){
					if(ma<k-j+1) ma=k-j+1;
				}
			}
		}
	}
	cout<<ma;
	return 0;
}
