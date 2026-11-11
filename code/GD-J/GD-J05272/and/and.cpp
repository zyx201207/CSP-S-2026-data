#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.in","r",stdin);
	reopen("1.out","w",stdout);
	int n,m,a[200005],ans=0b[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=1;j<n;j++){
		for(int i=j;i<n;i++){
			if(a[i]<a[i-1]){
				int k=a[i];
				a[i]=a[i-1];
				a[i-1]=k;
			}
		}
	}
	if(n==m){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans & a[i];
		}
	}else{
		ans=a[n-1];
		for(int i=2;i<m;i++){
			ans=ans & a[n-i];
		}
	}
	cout<<ans;
    return 0;
}
