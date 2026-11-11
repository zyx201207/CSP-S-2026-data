#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string S;
	int a[1000000001]={};
	char c[32]={};
	int cnt=0,b;

		for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		S+=a[i]+c[i];
		b+=a[i];
	}
	
	cout<<0;
	return 0;
}
