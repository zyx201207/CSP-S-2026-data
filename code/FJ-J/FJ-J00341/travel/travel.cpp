#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2)) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(s1[s1.size()-1]=='A'&&(s2[s2.size()-1]=='B'||s2[s2.size()-1]=='C'))cout<<1;
	else if(s1[s1.size()-1]=='B'&&(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='C'))cout<<1;
	else if(s1[s1.size()-1]=='C'&&(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='B'))cout<<1;
	else if(s1[s1.size()-1]=='E'&&s2[s2.size()-1]=='F')cout<<11;
	else if(s1[s1.size()-1]=='F'&&s2[s2.size()-1]=='E')cout<<11;
	else cout<<0;
	if(s1[s1.size()-1]=='A'&&s2[s2.size()-1]=='B')cout<<1;
	else if(s1[s1.size()-1]=='B'&&(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='C'))cout<<1;
	else if(s1[s1.size()-1]=='C'&&s2[s2.size()-1]=='B')cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
