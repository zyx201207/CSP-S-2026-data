#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	
	
	if(c1==c2) {cout<<1;}
	else cout<<0;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]){cout<<1;}
	else cout<<0;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]){
		char s12,s22;
		s12=s1[2],s22=s2[2];
		if((s12=='A' && s22=='B') || (s12=='A' && s22=='C') 
		|| (s12=='B' && s22=='A') || (s12=='B' && s22=='C')
		|| (s12=='C' && s22=='A') || (s12=='C' && s22=='B')
		|| (s12=='F' && s22=='D') || (s12=='D' && s22=='F')
		)cout<<1;
		else cout<<0;
	}else cout<<0;
	
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]){
		char s12,s22;
		s12=s1[2],s22=s2[2];
		if((s12=='A' && s22=='B') || (s12=='C' && s22=='B')
		|| (s12=='B' && s22=='A') || (s12=='B' && s22=='C')
		|| (s12=='F' && s22=='D') || (s12=='D' && s22=='F')
		)cout<<1;
		else cout<<0;
	}else cout<<0;
}
int main(){
	 freopen("travel.in","r",stdin);
	 freopen("travel.out","w",stdout);
	
    //	ios::sync_with_stdio(false);
	//cin.tie(nullptr);cout.tie(nullptr);
	
	solve();
	
	fclose(stdin);
   	fclose(stdout);
	return 0;
}
// 12 9:02 -- wcqk HB-J00870
