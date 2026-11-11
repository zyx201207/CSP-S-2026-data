#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int num;
		char zimu;
		cin>>num>>zimu;
		for(int j=1;j<=num;j++){
			s[i]=zimu;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<s[i];
	}
	return 0;
}
