#include <bits/stdc++.h> 
using namespace std;
int a1,b1,a2,b2;
char c1,c2;
bool p1,p2,p3;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(!p1 && s[i]==' '){
			p1=1;continue;
		}else if(!p2 && s[i]==' '){
			p2=1;continue;
		}else if(!p3 && s[i]==' '){
			p3=1;continue;
		}if(s[i]>='0' &&s[i]<='9'){
			if(!p1)a1=a1*10+s[i]-'0';
			else if(!p2)b1=b1*10+s[i]-'0';
			else if(!p3)a2=a2*10+s[i]-'0';
			else b2=b2*10+s[i]-'0';
		}else if(s[i]>='A' && s[i]<='F' && s[i]!='E'){
			if(!p2)c1=s[i];
			else c2=s[i];
		}
	}if(a1==a2){
		cout <<1;
		if(b1==b2){
			cout <<1;
			if((c1>='A'&&c1<='C') && (c2>='A'&&c2<='C')){
				cout <<"1";
				if(c2==c1+1)cout <<1;
				else cout <<0;
			}else if(c1=='D' && c2=='F'){
				cout <<"11";
			}else cout <<"00";
		}else{
			cout <<"000";
		}
	}else cout <<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
