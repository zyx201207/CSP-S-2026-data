#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	getline(cin,c1);
	getline(cin,s1);
	getline(cin,c2);
	getline(cin,s2);
	int i=s1.size();
	int j=s2.size();
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==s2){
		cout<<1;
	}else{
		cout<<0;
	}
	s1[i]=s1[i]+1;
	if(s1[i]==s2[j]){
		cout<<1;
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
}
	return 0;
} 
