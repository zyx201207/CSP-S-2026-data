#include<bits/stdc++.h>
using namespace std;
int c1,c2,pai=0,ce=0,lin=0;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) pai=1;

	if(pai){
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') ce=1;
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') ce=1;
	}

	if(ce){
		if(abs(s1[2]-s2[2])==1) lin=1;
		if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')) lin=0;
	}
	cout<<1<<pai<<ce<<lin;
	return 0;
}
