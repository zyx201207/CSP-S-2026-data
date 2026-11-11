#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200000],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;i++){
			int ans0=i&j;
			if(ans0>ans){
				ans=ans0;
			}
		}
	}
	cout<<ans;
	return 0;
}
