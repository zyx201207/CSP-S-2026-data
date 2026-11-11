//GZ-J00134 南白初级中学 唐清倾 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	bool t=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else {
		t=1;
		cout<<0;
	}
	if(s1[1]==s2[1] && s1[0]==s2[0] && t==0) cout<<1;
	else {
		t=1;
		cout<<0;
	}
	string s;
	s+=s1[2];
	s+=s2[2];
	if((s=="AB" || s=="BA"|| s=="AC"|| s=="CA"|| s=="BC"|| s=="CB"|| s=="DF"|| s=="FD") && t==0)
		cout<<1;
	else {
		t=1;
		cout<<0;
	}
	if((s=="AB"|| s=="BA"|| s=="BC"|| s=="CB"|| s=="DF"|| s=="FD") && t==0)
		cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
}

