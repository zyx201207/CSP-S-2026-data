#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long o=0,p=0,f=0,g=0;
string s="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	for(long long i=0;i<a.size();i++){
		o=o*10+a[i]-'0';
	}
	for(long long i=0;i<c.size();i++){
		p=p*10+c[i]-'0';
	}
	if(o==p){
		s[0]='1';
	}
	if(s[0]=='1'){
		for(int i=0;i<b.size()-1;i++){
			f=f*10+b[i]-'0';
		}
		for(int i=0;i<d.size()-1;i++){
			g=g*10+d[i]-'0';
		}
		if(f==g){
			s[1]='1';
		}
		if(s[1]=='1'){
//			if(abs(b[2]-d[2])==1 && !((b[2]=='c' && d[2]=='d') || (b[2]=='d' && d[2]=='c'))){
//				
//			}
			map<char,long long> k;
			k['A']=k['B']=k['C']=1;
			k['D']=k['F']=2;
			if(k[d[2]]==k[b[2]]){
				s[2]='1';
			}
			if(s[2]=='1'){
				k['A']=1;
				k['B']=2;
				k['C']=3;
				k['D']=10;
				k['F']=11;
				if(abs(k[b[2]]-k[d[2]])==1){
					s[3]='1';
				}
			}
		}
	}
	cout << s;
	return 0;
}
