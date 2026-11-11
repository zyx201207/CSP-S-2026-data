#include<bits/stdc++.h>
using namespace std;
inline bool in_the_same_side(string a,string b){
	char side_a=a[2],side_b=b[2];
	return (((side_a>='A')&&(side_a<='C')&&(side_b>='A')&&(side_b<='C'))||
			((side_a=='D')&&(side_a=='F')&&(side_a=='D')&&(side_a<='F')));
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			cout<<'1';
			if(in_the_same_side(s1,s2)){
				cout<<'1';
				if((max(s1[2],s2[2])-min(s1[2],s2[2]))==1&&(!(
				   (max(s1[2],s2[2])=='D')&&(min(s1[2],s2[2])=='C')))){cout<<'1';}
				else{cout<<'0';}
			}else{cout<<'0'<<'0';}
		}else{cout<<'0'<<'0'<<'0';}
	}else{cout<<'0'<<'0'<<'0'<<'0';}
	return 0;
}
