#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1_,s1_,c2_,s2_;
bool f[4];
string tmp1,tmp2;
char t1,t2;
bool pd1(char a,char b){
	if(a=='A'){
		if(b=='B'||b=='C')return 1;
		return 0;
	}else if(a=='B'){
		if(b=='A'||b=='C')return 1;
		return 0;
	}else if(a=='C'){
		if(b=='A'||b=='B')return 1;
		return 0;
	}else if(a=='D'){
		if(b=='F')return 1;
		return 0;
	}else if(a=='F'){
		if(b=='D')return 1;
		return 0;
	}
	if(b=='A'){
		if(a=='B'||a=='C')return 1;
		return 0;
	}else if(b=='B'){
		if(a=='A'||a=='C')return 1;
		return 0;
	}else if(b=='C'){
		if(a=='A'||a=='B')return 1;
		return 0;
	}else if(b=='D'){
		if(a=='F')return 1;
		return 0;
	}else if(b=='F'){
		if(a=='D')return 1;
		return 0;
	}
}
bool pd2(char a,char b){
	if((a=='A'||a=='C')&&b=='B')return 1;
	if(a=='B'&&(b=='A'||b=='C'))return 1;
	if(a=='D'&&b=='F')return 1;
	if(a=='F'&&b=='D')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1_>>s1_>>c2_>>s2_;
	for(int i=0;i<s1_.size();i++)
		if(isdigit(s1_[i]))tmp1+=s1_[i];
	for(int i=0;i<s2_.size();i++)
		if(isdigit(s2_[i]))tmp2+=s2_[i];
	t1=s1_[2],t2=s2_[2];
	if(c1_==c2_){
		f[0]=1;
		if(tmp1==tmp2){
			f[1]=1;
			if(pd1(t1,t2)){
				f[2]=1;
				if(pd2(t1,t2))
					f[3]=1;
			}
		}
	}
	for(int i=0;i<4;i++)cout<<f[i];
	return 0;
}
