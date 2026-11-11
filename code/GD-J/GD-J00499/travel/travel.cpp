#include<bits/stdc++.h>
using namespace std;
void solve(){
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	string ans;
	if(a1!=b1)ans+='0';
	else ans+='1';
	int s1=0,s2=0;
	for(int i=0;i<2;i++)s1=s1*10+(int)(a2[i]-'0');
	for(int i=0;i<2;i++)s2=s2*10+(int)(b2[i]-'0');
	
	if(s1==s2 and a1==b1)ans+='1';
	else ans+='0';
	char a=a2[2],b=b2[2];
	if(((a<='C' and a>='A' and b<='C' and b>='A' )or(a<='E' and a>='D' and b<='E' and b>='D')) and a1==b1)ans+='1';
	else ans+='0';
	if(a>b)swap(a,b);
	if((a=='A' and b=='B') or (a=='B' and b=='C') or (a=='D' and b=='E') and a1==b1)ans+='1';
	else ans+='0';
	cout<<ans;
	
}
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	solve();
	return 0;
} 
