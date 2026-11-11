#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],a2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	for(int j=1;j<=i;j++){
		if(a[i]==a2){
			cout<<a[i];
			return 0;
		}
	}
		a2=a[i];	
	}
	
	return 0;
}
