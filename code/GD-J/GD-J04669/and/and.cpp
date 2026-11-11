#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[999999];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	cout<<a[n];
	return 0;
}
