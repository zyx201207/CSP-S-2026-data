#include<bits/stdc++.h>
using namespace std;
bool kk(string aaa,string bbb){
	char a=aaa[2],b=bbb[2];
	if(a=='D'&&b=='F')return 1;
	if(a=='F'&&b=='D')return 1;
	if(a>='A'&&a<='C'&&b>='A'&&b<='C')return 1;
	return 0;
}
bool ksk(string aaa,string bbb){
	int a=aaa[2],b=bbb[2];
	if(abs(a-b)==1){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c;
	cin>>s;
	cin>>cc;
	cin>>ss;
	if(c==cc){
		cout<<1;
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<1;
			if(kk(s,ss)){
				cout<<1;
				if(ksk(s,ss)){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}
