#include<bits/stdc++.h>
using namespace std;
long long n,x,m;
string a;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		m+=x;
	}
	cout<<m/2<<endl;
	return 0;
}
