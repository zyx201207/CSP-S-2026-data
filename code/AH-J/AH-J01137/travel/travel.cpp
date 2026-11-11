#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>s1>>b>>s2;
	c=(s1[0]-'0')*10+(s1[1]-'0');
	d=(s2[0]-'0')*10+(s2[1]-'0');	
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')) || ((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E'))){
				cout<<1;
				if(s1[2]-1==s2[2] || s1[2]+1==s2[2])cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
