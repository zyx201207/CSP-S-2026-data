#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE 1
#define duoce 0
typedef long long ll;
const int N=1e5+5;
void solve();
int main(){
	if(ONLINE_JUDGE){
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
	}
	int t=1;
	if(duoce)cin>>t;
	while(t--)solve();
}
void solve(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string s=s1.substr(0,2);
	string ss=s2.substr(0,2);
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s==ss)cout<<1;
	else cout<<0;
	if(c1==c2&&s==ss&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
		cout<<1;
	}
	else cout<<0;
	if(c1==c2&&s==ss&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&max(s1[2],s2[2])-min(s1[2],s2[2])==1){
		cout<<1;
	}
	else cout<<0;
}
