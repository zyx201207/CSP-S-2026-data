#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long cnt;
void f(string x){
	for(int i=0;i<=x.size()/2-1;i++){
		if(x[i]!=x[x.size()-i-1])cnt++;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char a;
		long long x;
		cin>>x>>a;
		for(long long j=1;j<=x;j++)s+=a;
		
	}
	f(s);
	cout<<cnt;
	return 0;
}
