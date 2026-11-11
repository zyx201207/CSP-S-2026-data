#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
bool check(char a,char b){
	if(a>='A' and a<='C' and b>='A' and b<='C')	return 1;
	if((a=='D' and b=='F') or (b=='D' and a=='F')) return 1;
	return 0;

}
bool check2(string a,string b){
	char ch1=a[2],ch2=b[2];
	if((ch1=='A' and ch2=='B') or (ch1=='B' and ch2=='C') or (ch1=='D' or ch2=='F'))
		return 1;
	return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;   
    string t1=s1.substr(0,2),t2=s2.substr(0,2);
    if(t1==t2 and c1==c2) cout<<1;
	else cout<<0;
	char ce1=s1[2],ce2=s2[2];
	if(t1==t2 and check(ce1,ce2) and c1==c2) cout<<1;
	else cout<<0;
	if(check2(s1,s2) and c1==c2) cout<<1;
	else cout<<0;
	return 0;
}

