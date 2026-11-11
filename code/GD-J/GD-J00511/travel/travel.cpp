#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
map<char,int> bh;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bh['A']=1;bh['B']=2;bh['C']=3;bh['D']=10;bh['F']=11;
	if (c1==c2){
		cout<<"1";
		int n1=(s1[0]-'0')*10+(s1[1]-'0');
		int n2=(s2[0]-'0')*10+(s2[1]-'0');
		if (n1==n2){
			cout<<"1";
			if (abs(bh[s1[2]]-bh[s2[2]])<=2){
				cout<<"1";
				if (abs(bh[s1[2]]-bh[s2[2]])==1) cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	
	
	
	return 0;
}
