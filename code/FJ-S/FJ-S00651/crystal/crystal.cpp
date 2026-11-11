#include<bits/stdc++.h>
using namespace std;
int n,a[500024],m,b[500024];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i*(a[2]-a[1])<=m){
			m-=i*(a[2]-a[1]);
		}else{
			cout<<i;
			return 0;
		}
	}
} 
