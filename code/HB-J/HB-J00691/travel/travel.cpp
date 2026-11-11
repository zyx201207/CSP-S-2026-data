#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout << 1;
	}
	else if(c1!=c2){
		cout << 0;
	}
	string ss="",sss="";
	int p=0;
	for(int i=0;i<(int)s1.size()-1;i++){
		ss+=s1[i];
		sss+=s2[i];
	}
	if(ss==sss){
		cout << 1;
	}
	else if(ss!=sss){
		cout << 0;
		p=1;
	}
	int pd=0;
	if(p==1)
	{
		cout << 0;
		pd=1;
	}
	else if((s1[s1.size()-1]=='D' || s1[s1.size()-1]=='F') and (s2[s2.size()-1]=='D' || s2[s2.size()-1]=='F') and !(s1[s1.size()-1]=='A' || s1[s1.size()-1]=='B' || s1[s1.size()-1]=='C')){
		cout << 1;
	}else if((s1[s1.size()-1]=='A' || s1[s1.size()-1]=='B' || s1[s1.size()-1]=='C') and (s2[s2.size()-1]=='A' || s2[s2.size()-1]=='B' || s2[s2.size()-1]=='C') and !(s1[s1.size()-1]=='D' || s1[s1.size()-1]=='F') and !(s2[s2.size()-1]=='D' || s2[s2.size()-1]=='F'))
	{
			cout << 1;
	}else {
		cout << 0;
		pd=1;
	}
	if(abs(s1[s1.size()-1]-s2[s2.size()-1])==1 and pd==0){
		cout << 1;
	}
	else if(abs(s1[s1.size()-1]-s2[s2.size()-1])!=1){
		cout << 0;
	}else if(pd==1){
		cout << 0;
	}
	return 0;
}
