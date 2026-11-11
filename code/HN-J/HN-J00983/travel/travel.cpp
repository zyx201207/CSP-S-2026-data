#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int hx[200];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	hx['A']=hx['B']=hx['C']=1;
	hx['D']=hx['F']=2;
	string p1=s1.substr(0,2);
	string p2=s2.substr(0,2);
	if(c1==c2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(hx[s1[2]]==hx[s2[2]]){
				cout<<1;
				if(!(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'))
					cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
