#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	cout<<(f1=(c1==c2));
	cout<<(f2=(f1&&s1[0]==s2[0]&&s1[1]==s2[1]));
	cout<<(f3=(f2&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C')));
	cout<<(f4=(f3&&(s1[2]=='D'&&s1[2]=='F'||s1[2]=='F'&&s2[2]=='D'||abs(s1[2]-s2[2])==1)));
	return 0;
} 
