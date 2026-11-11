#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ai;
	long long ct;
	char ci;//ci>='a'&&ci<='z'
	string s;
	for(int i=1;i<=n;i++){
		cin>>ai>>ci;
		for(int j=0;j<ai;j++){
			s[j]=ci;
		}
	}
	string s1=s;
	reverse(s1.begin(),s1.end());
	if(s1==s){
		cout<<0;
		return 0;
	}else if(n==1){
		cout<<0;
		return 0;
	}else{
		//ct!=0
		
	}
	return 0;
} 
