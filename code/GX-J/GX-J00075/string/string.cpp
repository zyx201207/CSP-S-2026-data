#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0;
	cin>>n;
	string a,b;
	for(int i=0;i<n;i++){
		int p;char v;cin>>p>>v;
		for(int j=0;j<p;j++){a=a+v;}
	}
	//~ cout<<a;
	for(int i=0;i<int(a.size())/2;i++){
		if(a[i]!=a[int(a.size())-i-1]) {s++;}
	}
	cout<<s;
	return 0;
}
