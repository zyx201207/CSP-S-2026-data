#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int c1,c2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){//在同一车厢
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){//同一排
			cout<<"1";
			if(s1[2]+s2[2]=='D'+'F' || (s1[2]+s2[2]>='A'+'B' && s1[2]+s2[2]<='B'+'C')){//同一侧
				cout<<"1";
				if(s1[2]+s2[2]=='D'+'F' || s1[2]+s2[2]=='A'+'B' || s1[2]+s2[2]=='C'+'B'){//相邻
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	
	
	return 0;
}