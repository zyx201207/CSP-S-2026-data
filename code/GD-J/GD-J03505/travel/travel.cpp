#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(x,a,b,c) for(int x=a;b;x+=c)
#define fop(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout);
const int INF=INT_MAX/3,N=1e5+20;
int c1,c2;
string s1,s2;
map<char,int> vis;
int main() {
	fop("travel");
	cin>>c1>>s1>>c2>>s2;
	vis['A']=vis['B']=vis['C']=1,vis['D']=vis['F']=2;	
	if(c1==c2) {
		cout<<'1';
		int a=(s1[0]-'0')*10+(s1[1]-'0');
		int b=(s2[0]-'0')*10+(s2[1]-'0');
		if(a==b) {
			cout<<'1';
			if(vis[s1[2]]==vis[s2[2]]){
				cout<<'1';
				char s1_c=s1[2],s2_c=s2[2];
				if(s1_c>s2_c) swap(s1_c,s2_c);
				if((s2_c=='F'&&s1_c=='D')||(s2_c=='C'&&s1_c=='B')||(s2_c=='B'&&s1_c=='A'))cout<<'1';
				else cout<<'0';	
			}else cout<<"00";
		}else cout<<"000";
	} else cout<<"0000";
	return 0;
}
