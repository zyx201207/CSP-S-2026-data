#include<bits/stdc++.h>
using namespace std;
const int N=20;
string c1,c2;
char s1[N],s2[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++) cin>>s1[i];
	cin>>c2;
	for(int i=1;i<=3;i++) cin>>s2[i];
	int x1=(s1[1]-'0')*10+s1[2]-'0',x2=(s2[1]-'0')*10+s2[2]-'0';
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(x1==x2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(s1[3]<='C'&&s2[3]<='C'||s1[3]>'C'&&s2[3]>'C') cout<<1;
	else{
		cout<<"00";
		return 0;
	} 
	if(s1[3]==s2[3]+1||s1[3]==s2[3]-1) cout<<"1";
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
