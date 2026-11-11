#include<bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int n,m,ans;
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n]; 
	return 0;
}
