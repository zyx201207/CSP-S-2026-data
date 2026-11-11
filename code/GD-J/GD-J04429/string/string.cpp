#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long lena=0;
	for(int i=0;i<n;i++){
		int t;
		char c;
		cin>>t>>c;
		for(int i=1;i<=t;i++)a+=c;
		lena+=t;
	}
	cout<<a<<endl;
	for(int i=0;i<lena/2;i++){
		if(a[i]!=a[lena-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
