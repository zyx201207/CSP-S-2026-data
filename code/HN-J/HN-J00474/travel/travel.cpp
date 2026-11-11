#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int l(char a){
	if(a=='F'||a=='D'){
		return 1;
	}return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(l(s1[2])==l(s2[2])){
				cout<<1;
				if(s1[2]=='F'||s1[2]=='D'){
					cout<<1;
				}else if(s1[2]=='B'||s2[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
