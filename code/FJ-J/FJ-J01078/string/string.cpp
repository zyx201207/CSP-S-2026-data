#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	int n,a[200005],m=1;char c[200005];
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n-1;i++){
		if(c[i]==c[i+1])m++;
	}
	if(m==n)cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}