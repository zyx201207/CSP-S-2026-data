#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int get(char a,bool s){
	if(s){
		if(a>='A'&&a<='C') return 1;
		return 2;
	}
	return a-'A';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(get(s1[2],1)==get(s2[2],1)){
				if(abs(get(s1[2],0)-get(s2[2],0))==1){
					cout<<"1111";
				}else cout<<"1110";
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
/*
HN-J00019
(签到) 1/1
这能挂分我吃 
while(1) rp++;
*/

