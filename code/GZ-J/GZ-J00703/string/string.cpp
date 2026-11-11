//GZ-J00703      高再蕤           遵义市第四初级中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0;
	string a;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=0;j<x;j++){
			a=a+y;
		}
	}
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]){
			l++;
		}
	}
	cout<<l;
	return 0;
}

