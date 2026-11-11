#include<bits/stdc++.h>
using namespace std;
int n,a[200000];
string s[200000];
int main(){
	freopen("string.in","r","stdin");
	freopen("string.our","w","stdour");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int z=0;
	for(int i=1;i<=n/2;i++){
		z+=a[i];
	}cout<<z;
	return 0;
}