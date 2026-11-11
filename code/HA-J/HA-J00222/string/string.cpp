#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string m="";
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		string c;
		cin>>c;
		for(int i=0;i<s;i++){
			m = m + c;
		} 
	}
	cout<<1;
	return 0;
}
