#include<bits/stdc++.h>
using namespace std;
	int c1,s1,c2,s2;
int main(){
	freopen("treavel.in";"r";stdin);
	freopen("treavl.out";"w";stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}	else{
			cout<<0;
		}
		if(s1==s2){
			cout<<1;
		}else{
			cout<<0;
		}
		if(s1-1==s2 || s1+1=s2){
			cout<<1;
		}
		else{
		cout<<0;
		}
		
}
