#include<bits/stdc++.h>
#define int long long
using namespace std;
int pd(char p){
	if(p=='A'||p=='B'||p=='C'){
		return 1;
	}
	else if(p=='D'||p=='F'){
		return 0;
	}
	return 0;
}
bool nxt(char d,char g){
	int l=(int)d-(int)g;
	if(l==1||l==-1){
		return true;
	}
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string k1="";
		k1+=s1[0];
		k1+=s1[1];
		string k2="";
		k2+=s2[0];
		k2+=s2[1];
		if(k1==k2){
			cout<<"1";
			char t1=s1[2];
			char t2=s2[2];
			if(pd(t1)==pd(t2)){
				cout<<"1";
				if(nxt(t1,t2)==true){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
