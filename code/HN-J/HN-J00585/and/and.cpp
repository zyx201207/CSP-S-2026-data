#include<bits/stdc++.h>
using namespace std;
const int N=+5;
int n,m,ml;
string s;
int a[100000000+5];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		ml=max(ml,x);
	}
	cout<<ml;
	return 0;
} 
