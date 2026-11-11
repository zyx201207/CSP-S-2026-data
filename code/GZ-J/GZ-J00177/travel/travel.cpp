//GZ-J00177 ∫ÿ¡ºÏœ 100fen
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,s_1,c_2,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	bool a_1=(c_1==c_2);
	bool b_1=(a_1 and s_1[0]==s_2[0] and s_1[1]==s_2[1]);
	bool c2_1=(b_1 and ((s_1[2]=='A' or s_1[2]=='B' or s_1[2]=='C') and (s_2[2]=='A' or s_2[2]=='B' or s_2[2]=='C')) or ((s_1[2]=='D' or s_1[2]=='F') and (s_2[2]=='D' or s_2[2]=='F')));
	bool d_1=(c2_1 and ((s_1[2]=='A' and s_2[2]=='B') or (s_1[2]=='B' and s_2[2]=='A') or (s_1[2]=='C' and s_2[2]=='B') or (s_1[2]=='B' and s_2[2]=='C') or (s_1[2]=='D' and s_2[2]=='F') or (s_1[2]=='F' and s_2[2]=='D')));
	if(a_1) cout<<1;
	else cout<<0;
	if(b_1) cout<<1;
	else cout<<0;
	if(c2_1) cout<<1;
	else cout<<0;
	if(d_1) cout<<1;
	else cout<<0;
	
	return 0;
}
