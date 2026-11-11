#include<bits/stdc++.h>
using namespace std;
string zfc;
int pd(string a){
	int cs=0;
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]){
			cs++;
		}
	}
	return cs;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,i=0;
	cin>>a;
	while(a--){
		int n;char m;
		cin>>n>>m;
		for(int j=0;j<n;j++){
			zfc.push_back(m);
		}	
	}
	cout<<pd(zfc);
}
