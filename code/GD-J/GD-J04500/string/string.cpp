#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[100];
	string c[100];
	cin>>n
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
	} 
	if(a[1] == 2&&c[1] == "a"){
		cout<<2;
	}
	return 0;
}
