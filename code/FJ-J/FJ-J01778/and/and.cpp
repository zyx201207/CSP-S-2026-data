#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c,b=1,a;
	for(int i=0;i<n;i++){
		cin>>a;
		c=a&b;
		b=a;
	}
	cout<<c;
	return 0;
}
