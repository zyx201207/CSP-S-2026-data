#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
string s1,s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int ok=(c1==c2);
	cout<<ok;
	int op=(s1[0]==s2[0]&&s1[1]==s2[1])&&ok;
	cout<<op;
	int opp;
	if(op&&((s1[2]>'C'&&s2[2]>'C')||(s1[2]<'D'&&s2[2]<'D'))){
		opp=1;
		cout<<opp;
	}
	else{
		opp=0;
		cout<<0;
	}
	if(opp&&abs(s1[2]-s2[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
