#include <bits/stdc++.h>
using namespace std;
long long n,a[1145141];
unsigned long long len;
string x;
int huiwen(string x){
	int ans=0;
	for(int i=0;i<x.length()/2;i++){
		if(x[i]!=x[x.length()-1-i]) ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		char u;
		cin>>a[i]>>u;
		for(int j=1;j<=a[i];j++){
			x+=u;
		}
		len+=a[i];
	}
	cout<<huiwen(x);
	return 0;
}
