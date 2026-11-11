#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			int s1n = s1[2]-'A',s2n = s2[2]-'A';
			if(s1n <= 4 && s1n >=3 && s2n<=2 && s2n>=0 || s2n <= 4 && s2n >=3 && s1n<=2 && s1n>=0 ){
				cout<<1100;
			}else{
				if(abs(s1n-s2n) == 1){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}
		}else{
			cout<<1000;
		}
	}else{
		cout<<0000;
	}
} 
