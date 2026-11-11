#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in.in","r",stdin);
	freopen("and.out.out","w",stdout);
	int a,b,c[100000];
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	cout<<c[a-1];
	return 0;
}
