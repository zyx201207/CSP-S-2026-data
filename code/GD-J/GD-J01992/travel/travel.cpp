#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int p1,p2;
char q1,q2;
int ans[10];
map<char,bool> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	mp['A']=mp['B']=mp['C']=0;
	mp['D']=mp['F']=1;
	for(int i=0;i<2;i++) p1=(p1*10+(b[i]-'0'));
	for(int i=0;i<2;i++) p2=(p2*10+(d[i]-'0'));
	q1=b[2],q2=d[2];
	ans[0]=1;
	ans[1]=ans[0]&(a==c?1:0);
	ans[2]=ans[1]&(p1==p2?1:0);
	ans[3]=ans[2]&(mp[q1]==mp[q2]?1:0);
	if(q1>q2) swap(q1,q2);
	int cur=0;
	if(q1=='A' && q2=='B') cur=1;
	if(q1=='B' && q2=='C') cur=1;
	if(q1=='D' && q2=='F') cur=1;
	ans[4]=ans[3]&cur;
	for(int i=1;i<=4;i++) cout<<ans[i];
	return 0;
}

