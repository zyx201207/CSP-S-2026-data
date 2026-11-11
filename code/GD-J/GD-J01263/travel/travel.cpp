#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
map<char,int> ma;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ma['A']=1;
	ma['B']=2;
	ma['C']=3;
	ma['D']=5;
	ma['F']=6;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]>='A'&&s1[2]<='C'){
				if(s2[2]>='A'&&s2[2]<='C'){
					if(abs(ma[s2[2]]-ma[s1[2]])==1) cout<<"1111";
					else cout<<"1110";
				}else cout<<"1100";
			}else if(s2[2]>='D'&&s2[2]<='F') cout<<"1111";
			else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
