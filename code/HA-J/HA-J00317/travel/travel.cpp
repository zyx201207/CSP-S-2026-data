#include<bits/stdc++.h>
using namespace std;
string C1,S1,C2,S2;
map<char,int> m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	m['A']=m['B']=m['C']=1;
	m['D']=m['F']=2;
	cin>>C1>>S1>>C2>>S2;
	if(C1==C2) cout<<1;
	else{cout<<"0000";return 0;}
	bool is=1;
	for(int i=0;i<=1;i++) if(S1[i]!=S2[i]) is=0;
	if(is) cout<<1;
	else{cout<<"000";return 0;}
	if(m[S1[2]]==m[S2[2]]) cout<<1;
	else{cout<<"00";return 0;}
	if((S1[2]=='A'&&S2[2]=='C')||(S1[2]=='C'&&S2[2]=='A')){cout<<"0";return 0;}
	cout<<1;
	return 0;
}
