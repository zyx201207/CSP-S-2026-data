#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	int l,o;
	char k,kk;
	cin>>c>>s>>cc>>ss;
	if(c==cc) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	l=s.size()-1;
	o=ss.size()-1;
	k=s[l];
	kk=ss[o];
	s.erase(l,1);
	ss.erase(o,1);
	if(s==ss) cout<<"1";
	else cout<<"0";
	if(s==ss){
		if(int(k)>=68&&int(kk)>=68){
			cout<<"11";
		}
		else if(int(k)<=67&&int(kk)<=67){
			cout<<"1";
			if(int(k)-1==int(kk)) cout<<"1";
			else if(int(k)==int(kk)-1) cout<<"1";
			else cout<<"0";
		}
		else cout<<"00";
	}
	else cout<<"00";
	return 0;
}
