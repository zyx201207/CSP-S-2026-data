#include<bits/stdc++.h>
using namespace std;
int n,c,t;
long long d,a[2000001],dc,m;
bool A;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dc=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=dc){
			A=1;
			break;
		}
	}
	if(A==0){
		m=d/dc;
		if(m<=1){
			cout<<0;
		}
		else{
			cout<<(n-2*m+1);
		}
		cout<<endl;
	}
}
	return 0;
}
