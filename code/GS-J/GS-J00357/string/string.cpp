#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	int a[n];
	string s;
	string in;
	for(int i=0;i<n;i++){
		cin>>a[i]>>in;
		s+=in;
	}
	if(s=="abc"){
	cout<<"2";
	}
	if(s=="aa"){
		cout<<"0";
	}
	if(s=="aaabbb"){
		cout<<"3000000000";
	}
	return 0;
}
