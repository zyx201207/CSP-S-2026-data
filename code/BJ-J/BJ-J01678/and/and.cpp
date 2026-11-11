#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001];
int ans=-1;
int sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		sum=a[i];
		for(int j=i+1;j<=n;j++){
			for(int z=1;z<=m;z++){
				if(j+z-1>n){
					continue;
				}else{
					sum=sum&a[j+z-1];
				}
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}