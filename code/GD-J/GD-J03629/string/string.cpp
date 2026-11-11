#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string ans="";
	
	int n;
	cin>>n;
	long long s=0;
	while(n--){
		int a;
		char t;
		cin>>a>>t;
		
		for(int i=1;i<=a;i++){
			ans+=t; 
			s++;
		}
	} 
	
	long long num=0;
	
	for(int i=0;i<s;i++){
		if(ans[i]!=ans[s-i-1]){
			num++;
		}
	}
	cout<<num/2;
	return 0;
} 
