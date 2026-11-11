#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,a,j,d=0;
	char c;
	string b;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>c;
		for(j=0;j<a;j++){
			b+=c;
		}
	}
	for(i=0;i<=b.size()/2;i++){
		if(b[i]!=b[b.size()-i]){
			d++;
		}
	}
	cout<<d;
	return 0;
}
