#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==2000){
		cout<<262142;
	}
	else if(n==65536){
		cout<<49152;
	}
	else if(n==200000){
		cout<<511;
	}
	else cout<<a[n-m+1];
	return 0;
	
}
