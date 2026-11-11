#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,c[10000];
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	cout<<c[a-1];
} 
