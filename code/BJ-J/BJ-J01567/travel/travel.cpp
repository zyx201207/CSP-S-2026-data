#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int toint(string s){
	int ans=0;
	int l=s.size();
	for(int i=0;i<l;i++){
		ans*=0;
		ans+=s[i]-48;
	} 
	return ans;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	cin>>s;
	int c1=toint(s);
	cin>>s;
	int s1=toint(s.substr(0,2));
	char d1=s[2];
	cin>>s;
	int c2=toint(s);
	cin>>s;
	int s2=toint(s.substr(0,2));
	char d2=s[2];
	if(c1==c2){
		if(s1==s2){
			bool e1=1,e2=1;
			if(d1=='D'||d1=='F')e1=0;
			if(d2=='D'||d2=='F')e2=0;
			if(e1==e2){
				if(abs(d1-d2)==1)cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
