#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	int n;
	int a;string c[N];
	cin>>n;
	string v,v2,v3;
	for(int i=0;i<n;i++){
		cin>>a>>c[i];
		for(int j=0;j<a;j++){
			v+=c[i];
			v3+=c[i];
		}
	}
	
	for(int i=v.size()-1;i>=0;i--){
		v2+=v[i];
	}
	if(v2==v)cout<<0;return 0;
	
	return 0;
}
