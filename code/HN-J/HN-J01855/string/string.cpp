#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ai;
	cin>>n;
	string s,ci;
	int c=0;
	for(int i=1;i<=n;i++){
		cin>>ai>>ci[i];
		for(int j=1;j<=ai;j++){
			s+=ci[i];
		}
	}
	cout<<c;
	
	return 0;
}
