#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=1;i<m;i++){
		ans=ans&a[n-1-i];
	}
	if(a[n-m]==a[n-m-1]){
		for(int i=m;i<n;i++){
			if(a[n-1-i]==a[n-m]){
				ans=ans|a[n-1-i+m];
			}
		}
	}
	cout<<ans;
	return 0;
}
	
