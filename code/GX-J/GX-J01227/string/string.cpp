#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		string b;
		cin>>b;
		for(int i=0;i<a;i++){
			s+=b;
		}
	}
	cout<<s.size()/2;
	return 0;
}
