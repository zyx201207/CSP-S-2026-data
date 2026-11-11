#include<bits/stdc++.h>
#define LL long long
#define P(i,s,t) for(int i=s;i<=t;++i)
#define S(i,s,t) for(int i=s;i>=t;--i)
using namespace std;
int a1,a2,a3,b1,b2,b3;
int t1,t2,t3,t4;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>a1>>s;
	a2=(s[0]-'0')*10+(s[1]-'0'),a3=s[2]-'A';
	cin>>b1>>s;
	b2=(s[0]-'0')*10+(s[1]-'0'),b3=s[2]-'A';
	if(a1==b1) t1=1;
	
	if(t1&&a2==b2) t2=1;
	
	if(t2&&((a3<3&&b3<3)||(a3>2&&b3>2))) t3=1;
	
	if(t3&&(a3-b3==1||b3-a3==1)) t4=1;
	
	cout<<t1<<t2<<t3<<t4;
	return 0;
}
