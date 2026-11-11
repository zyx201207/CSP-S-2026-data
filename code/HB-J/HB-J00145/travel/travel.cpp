#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	freopen("travel.in","r",stdin); freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2; if(c1==c2){
		f1=true;
	}
	if(f1 && s1[0]==s2[0] && s1[1]==s2[1]){
		f2=true;
	}
	if(s1[2]=='A' && (s2[2]=='B' || s2[2]=='C')) f3=true;
	if(f3 || (s1[2]=='B' && (s2[2]=='A' || s2[2]=='C'))) f3=true;
	if(f3 || (s1[2]=='C' && (s2[2]=='B' || s2[2]=='A'))) f3=true;
	if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) f3=true;
	if(f1 && f2 && f3){
		f3=true;
	}
	if(max(s1[2],s2[2])-min(s1[2],s2[2])==1){
		if((s1[2]!='D' && s2[2]!='C') && (s1[2]!='C' && s2[2]!='D')) f4=true;
	}
    if((s1[2]=='D'&&s2[2]=='E')||(s2[2]=='D'&&s1[2]=='E')) f4==true;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
