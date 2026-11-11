#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m[1000000],b=0,v;
	char a[1000000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>a[i];
	}
	v=n/2;
	for(int j=0;j<v;j++){
		if(a[j]!=a[n-j-1]){
			b+=max(m[j],m[n-j-1]);
		}
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
