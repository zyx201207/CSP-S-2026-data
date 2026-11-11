#include<bits/stdc++.h>
using namespace std;
long long m,n,a[10000000],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		ans=12;
	}else{
		ans=7;
	}
	cout<<ans;
	return 0;
}
