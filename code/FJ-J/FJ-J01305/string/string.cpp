#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
string str;
long long m,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char a;
		cin>>x>>a;
		while(x--) str+=a;
	}
	m=str.size();
	for(int i=0;i<(m+1)/2;i++){
		if(str[i]!=str[m-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}