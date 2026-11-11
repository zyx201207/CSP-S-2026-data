#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==a[2]){
		cout<<a[1];
	}else{
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
