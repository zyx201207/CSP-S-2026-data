#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,Mod=998244353;
void solve(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char s10=s1[0],s11=s1[1],s12=s1[2];
	char s20=s2[0],s21=s2[1],s22=s2[2];
	if(c1==c2){
		cout<<1;
		if(s10==s20&&s11==s21){
			cout<<1;
			if((s12<='C'&&s22<='C')||(s12>='D'&&s22>='D')){
				cout<<1;
				if((s12=='A'&&s22=='B')||(s12=='B'&&s22=='A')
				 ||(s12=='B'&&s22=='C')||(s12=='C'&&s22=='B')
				 ||(s12=='D'&&s22=='F')||(s12=='F'&&s22=='D'))
				 	cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";	
} 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--)
		solve();
	return 0;
}
