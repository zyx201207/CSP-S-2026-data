#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int num=0;
	cin>>num;
	string s;
	for(int i=0;i<num;i++){
		int a;
		cin>>a;
		string b;
		cin>>b;
		for(int j=0;j<a;j++){
		s+=b;	
		}
 }

	for(int k=0;k<s.size();k++){
		int vum=s.size()-k;
		if(s[k]!=s[vum]){
			num++;
		}
	}
	cout<<num/2;
	return 0;
	}
	
