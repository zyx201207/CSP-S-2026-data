#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
#define HMY return
#define pb push_back()
#define pii pair<int,int>
//mt19937 rng(time(0));
signed main(){
	FILE("travel")
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	int t1=(s1[0]-'0')*10+(s1[1]-'0'),t2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==c2&&t1==t2) cout<<"1";
	else cout<<"0";
	if(c1==c2&&t1==t2&&(('A'<=s1[2]&&'C'>=s1[2]&&'A'<=s2[2]&&'C'>=s2[2])||('D'<=s2[2]&&'F'>=s2[2]&&'D'<=s1[2]&&'F'>=s1[2]))) cout<<"1";
	else cout<<"0";
	//cout<<s1[2]<<" "<<s2[2]<<" "<<((s1[2]=='A'&&s2[2]!='C')||(s1[2]=='C'&&s2[2]!='A')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))<<"\n";
	if(c1==c2&&t1==t2&&(('A'<=s1[2]&&'C'>=s1[2]&&'A'<=s2[2]&&'C'>=s2[2])||('D'<=s2[2]&&'F'>=s2[2]&&'D'<=s1[2]&&'F'>=s1[2]))&&((s1[2]=='A'&&s2[2]!='C')||(s1[2]=='C'&&s2[2]!='A')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))) cout<<"1";
	else cout<<"0";
	HMY 0;// yi tuo shi shan
}
// CSPJ GO GO GO!
// zip password:Trick||Treat!
// T1
//hyw? T1 2kib??
