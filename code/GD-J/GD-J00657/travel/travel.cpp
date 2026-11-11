#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
bool b,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		c=1;
		cout<<1;
	}else cout<<0; 
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c){
		b=1;
		cout<<1;
	}
	else cout<<0;
	if(((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='A'&&s2[2]<='C'))&&b) cout<<1;
	else cout<<0;
	if((s1[2]+1==s2[2]||s1[2]-1==s2[2])&&!((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D'))&&b) cout<<1;
	else cout<<0;
	return 0;
}
