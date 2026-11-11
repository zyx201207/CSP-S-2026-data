#include<bits/stdc++.h>
using namespace std;
char a[100000000];
int main(){
	int n;
	cin>>n;
	long long v=1;
	long long si=0;
	for(int i=1;i<=n;i++){
		char g;
		long long u;
		cin>>u>>g;
		for(int j=v;j<=v+u;j++){
			a[j]=g;
		}
		si+=u;
	}
	long long ans=0;
	for(int i=1;i<=si/2;i++){
		if(a[i]!=a[si-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
