#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b;
int c,d;
string e;
signed main(){
	cin>>c;
	for(int i=0;i<c;i++){
		cin>>d>>e;
		for(int j=0;j<d;j++){
			a+=e;
		}
	}a=string(a);
	c=0;
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-1-i]){
			c++;
		}
	}cout<<c;
}
