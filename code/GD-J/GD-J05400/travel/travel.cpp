#include<bits/stdc++.h>
using namespace std;
int f;
string s,a,ss,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>a>>ss>>b;
	if(s==ss) cout<<1;
	else cout<<0;
	if(s==ss&&a[0]==b[0]&&a[1]==b[1]) cout<<1;
	else cout<<0;
	if(s==ss&&a[0]==b[0]&&a[1]==b[1]
	&&(((a[2]=='A'||a[2]=='B'||a[2]=='C')
	&&(b[2]=='A'||b[2]=='B'||b[2]=='C'))||
	(a[2]=='D'||a[2]=='E')&&(b[2]=='D'||b[2]=='E'))) {
		cout<<1;
		f=1;
	}
	else cout<<0;
	if(f&&((a[2]-'A'==b[2]-'A'+1)||(b[2]-'A'==a[2]-'A'+1))) cout<<1;
	else cout<<0;
	return 0;
}
