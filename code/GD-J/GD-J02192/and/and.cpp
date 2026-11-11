#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int z=a[i];
		for(int j=1;j<=m;j++){
			for(int l=1;l<=n;l++){
				if(i!=l){
					ans=max(ans,z&a[l]);
				}
			}
			z=ans;
		}
	}
	cout<<ans;
	return 0;
}
