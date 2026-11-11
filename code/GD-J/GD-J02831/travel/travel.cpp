#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	string check="0000";
	if(c1==c2){
		check[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			check[1]='1';
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
				check[2]='1';
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
					check[3]='1';
				}
			}
		}
	}
	cout<<check;
	return 0;
} 
