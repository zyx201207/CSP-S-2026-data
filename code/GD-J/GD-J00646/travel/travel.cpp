#include<bits/stdc++.h>
using namespace std;
inline string check(int q,int p){
	if(q>p)swap(q,p);
	if(q=='D'-'A'&&p=='F'-'A')return "11";
	if(q<='C'-'A'&&'D'-'A'<=p)return "00";
	if((q=='A'-'A'&&p=='B'-'A')||(q=='B'-'A'&&p=='C'-'A'))return "11";
	return "10";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//É¾×¢ÊÍ
	
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000\n";
		return 0;
	}else cout<<"1";
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000\n";
		return 0;
	}else cout<<"1";
	cout<<check(s1[2]-'A',s2[2]-'A')<<'\n';
	return 0;
} 
