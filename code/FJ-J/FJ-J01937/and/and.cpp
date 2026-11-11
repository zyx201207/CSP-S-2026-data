#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,c;
	int b[10005];
	for(int i;i<=a;i++){
		cin>>b[i];
	}
	c=max(b[i]%9,b[i+1]%9);
	cout<<c;
	return 0;
}
	
