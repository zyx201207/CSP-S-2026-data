#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int a,b,se,aa,bb,sa;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c >> s >> cc >> ss;
	a=(c[1]-'0')+((c[0]-'0')*10);
	b=(s[1]-'0')+((s[0]-'0')*10);
	aa=(cc[1]-'0')+((cc[0]-'0')*10);
	bb=(ss[1]-'0')+((ss[0]-'0')*10);
	se=int(s[2]-'A')+1;
	sa=int(ss[2]-'A')+1;
	if(a!=aa)cout<<"0000";
	else if(b!=bb)cout<<"1000";
	else if(!((se<=3&&sa<=3)||(se>=4&&sa>=4)))cout<<"1100";
	else{
		if(se<sa)swap(se,sa);
		if((se-sa==1&&se!=4)||(se==6&&sa==4))cout<<"1111";
		else cout<<"1110";
	}
	return 0;
}
