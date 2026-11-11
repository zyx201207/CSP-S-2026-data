#include <bits/stdc++.h> 
using namespace std;
int a[500003];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int q=0;
			for(int z=i;z<j;z++){
				q+=a[j]-a[z];
			}
			if(q<=m){
				if(j-i+1>ans){
					ans=j-i+1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

