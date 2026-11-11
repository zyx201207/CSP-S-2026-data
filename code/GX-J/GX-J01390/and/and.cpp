#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		
			
				max(ans,a[i]);
			
		
	}
	cout<<ans;
	return 0;
}
