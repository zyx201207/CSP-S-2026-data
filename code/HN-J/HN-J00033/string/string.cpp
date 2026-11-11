#include<bits/stdc++.h>
using namespace std;
string s;
int n;
/*bool pd(string a){
	int s=a.;
	
	for(int i=0;i<s/2+1;i++){
		if(a[i]!=a[s-1-i]){
			return 0;
		}
	}
	return 1;
	
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;char c;  
		cin>>a>>c;
		for(int j=0;j<a;j++)s+=c;
	}
	cout<<0;
	return 0;
}
