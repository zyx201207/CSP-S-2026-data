#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1=c2) cout<<1;
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	int sum1=1,sum2=1;
	if(s1[2]=='F'||s1[2]=='D') sum1+=1;
	if(s2[2]=='F'||s2[2]=='D') sum2+=1;
	if(sum1==sum2) cout<<1;
	else cout<<0;
	int n1=s1[2],n2=s2[2];		
	if(abs(n1-n2)==1&&s1[2]!='D'&&s2[2]!='C'&&s1[2]!='C'&&s2[2]!='D') 
		cout<<1;
	else cout<<0;
	return 0;
	}