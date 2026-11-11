#include<bits/stdc++.h>
using namespace std;
int n,s=0;
int a[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c,b,d;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=0;j<a[i];j++){
			b+=c[i];
		}
	}
	for(int i=b.size()-1;i>=0;i--){
		d+=b[i];
	}
	for(int i=b.size()/2;i<b.size();i++){
		if(b[i]!=d[i]){
			s++;
		}
	}
	cout<<s;
	return 0;
}
