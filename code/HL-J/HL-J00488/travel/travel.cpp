#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
string s1a,s1b,s2a,s2b;
bool l,k;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	s1a=s1[0];
	s1a+=s1[1];
	s1b=s1[2];
	s2a=s2[0];
	s2a+=s2[1];
	s2b=s2[2];
	//cout<<s1a<<" "<<s1b<<" "<<s2a<<" "<<s2b<<" ";
	cout<<(s1a==s2a&&c1==c2)?1:0;
	if(("A"<=s1b&&s1b<="C")&&("A"<=s2b&&s2b<="C")){
		l=1;
	}
	if((s1b=="D"||s1b=="F")&&(s2b=="D"||s2b=="F")){
		l=1;
	}
	if(s1a==s2a&&c1==c2&&l==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(((s1b=="A"&&s2b=="B")||(s1b=="B"&&(s2b=="A"||s2b=="C"))||(s1b=="C"&&s2b=="B"))||((s1b=="D"&&s2b=="F")||(s1b=="F"&&s2b=="D"))){
		k=1;
	}
	if(s1a==s2a&&c1==c2&&l==1&&k==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
}
