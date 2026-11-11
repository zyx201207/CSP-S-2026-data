#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,tp1,tp2;
string c1,s1,c2,s2;
char a[15],b[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a[0]=s1[0],a[1]=s1[1];
	b[0]=s2[0],b[1]=s2[1];
	tp1=(a[0]-'0'*10)+a[1]-'0';
	tp2=(b[0]-'0'*10)+b[1]-'0';
	if(c1==c2) cout<<"1";
	else cout<<"0";
	if(tp1==tp2&&c1==c2) cout<<"1";
	else cout<<"0";
	if((tp1==tp2&&c1==c2)&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'))){
		cout<<"1";
		if(abs(s1[2]-s2[2])==1) cout<<"1";
		else cout<<"0";
	}
	else cout<<"00";
	return 0;
}
//Âå¹ÈÃû³Æ: ducz   Çó¹Ø
//We Fuck CCF!!! 
