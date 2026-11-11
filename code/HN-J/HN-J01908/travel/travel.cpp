#include<bits/stdc++.h>
using namespace std;
bool z;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string s="0000";
	if(a==c){
		s[0]='1';
		if(b[0]==d[0] && b[1]==d[1]){
			s[1]='1';
			if(b[2]-'A'<=2 && d[2]-'A'<=2){
				s[2]='1';
				int m=b[2],n=d[2];
				if(m-n==1 || n-m==1) s[3]='1';
			}
			else if(b[2]-'A'>2 && d[2]-'A'>2){
				s[2]='1';
				int m=b[2],n=d[2];
				if(m-n==1 || n-m==1) s[3]='1';
			}
		}
	}
	for(int i=0;i<s.size();i++){
		cout<<s[i];
	}
	return 0;
}
