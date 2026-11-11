#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int b[200005]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=a.size()-1;j++) b[i]=b[i]+a[j]*(10*(a.size()-1-j))%2;
	}
	cout<<a[n];
}
