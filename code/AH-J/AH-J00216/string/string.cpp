#include<bits/stdc++.h>
using namespace std;
int aa[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c;
	char b;
	int n,a,a1;
	cin>>n;
	if(n==1){
		cout<<'0';
	}
	if(n==2){
		cin>>a>>b;
		cin>>a1>>b;
		cout<<min(a1,a);
	}
	return 0;
}
