#include<bits/stdc++.h>
using namespace std;
string c,s,c2,s2;
bool f[30][30];
bool cx(){return c==c2;}
bool pai(){return s[0]==s2[0]&&s[1]==s2[1];}
bool ce(){return f[s[2]-'A'][s2[2]-'A']||f[s2[2]-'A'][s[2]-'A'];}
bool xl(){return s[2]+1==s2[2]||s2[2]+1==s[2]||(s[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s[2]=='F');}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	f['A'-'A']['B'-'A']=f['B'-'A']['C'-'A']=f['A'-'A']['C'-'A']=f['D'-'A']['F'-'A']=1;
//	cout<<f['C'-'A']['D'-'A'];
	cout<<(cx());
	cout<<(cx()&&pai());
	cout<<(cx()&&pai()&&ce());
	cout<<(cx()&&pai()&&ce()&&xl());
	return 0;
}

