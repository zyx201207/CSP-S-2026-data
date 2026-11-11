#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[2000005];
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=ans;
	for(int i=1;i<=n;i++){
		ans=a[i] and a[i-1];
		if(ans>=maxx){
			maxx=ans;
		}
	} 
	cout<<maxx;
	return 0;
}
