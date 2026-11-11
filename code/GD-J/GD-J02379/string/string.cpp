#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,n,v,l=1;
	int m=0,o=0;
	string c;
	cin>>n;
	string b[200003];
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		m=m+a;
		for(int j=l;j<a+l;j++){
			b[j]=c;
		}
		l+=a;
	}
	v=m/2;
	for(int i=1;i<=v;i++){
		if(b[i]!=b[m-i+1]){
			o+=1;
		}
	}
	cout<<o;
	return 0;
}
