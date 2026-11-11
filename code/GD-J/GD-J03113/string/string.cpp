#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t=0;
	cin>>n;
	vector<int>a(n);
	vector<char>c(n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(c[0]!=c[n]){
		t++;
	}
	cout<<t*a[1];
	return 0;
}
