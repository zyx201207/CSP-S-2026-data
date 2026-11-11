#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000005],p;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p=a[i]-a[i-1];
		if(m>=p)
			f=1;
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	int x=m/p;
	if(x<2){
		cout<<0;
		return 0;
	}
	if(x>=3){
		cout<<0;
		return 0;
	}
	else{
		cout<<n-3;
		return 0;
	}
	return 0;
}
