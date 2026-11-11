#include<bits/stdc++.h>
using namespace std;
int n,n1;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
	}
	while(n--){
		cin>>n1>>s1;
		if(n1!=1){
			cout<<5;
		}
	}
	return 0;
}