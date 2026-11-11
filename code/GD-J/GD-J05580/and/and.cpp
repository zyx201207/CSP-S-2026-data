#include<bits/stdc++.h>
using namespace std;
int c[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a);
	cout<<c[a-b];
	return 0;
} 
