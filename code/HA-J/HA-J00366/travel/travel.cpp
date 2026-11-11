#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
string a,b,c,d;
string ans;
bool pd2(){
	string s1="",s2="";
	s1+=b[0],s2+=d[0];
	s1+=b[1],s2+=d[1];
	if(s1==s2) return true;
	else return false;
}
bool pd3(){
	int l=b[2]-'A',r=d[2]-'A';
	if(l==3) l++;
	if(r==3) r++;
	if((l<3&&r<3)||(l>=4&&r>=4)){
		return true;
	}
	else return false;
}
bool pd4(){
	int l=b[2]-'A',r=d[2]-'A';
	if(l==3) l++;
	if(r==3) r++;
	if(abs(l-r)==1) return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans="1";
		if(pd2()){
			ans+="1";
			if(pd3()){
				ans+="1";
				if(pd4()){
					ans+="1";
				}
				else ans+="0";
			}
			else ans+="00";
		}
		else ans+="000";
	}
	else ans="0000";
	cout<<ans;
	return 0;
}
