#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx){
			mx=a[i];
		}
	}
	if(m==1){
		cout<<mx;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	return 0;
 }
