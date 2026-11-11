#include <bits/stdc++.h>
#define LL long long
#define AC return 0
using namespace std;
const int N=1e6+10;
string c1,c2,c3,c4;
bool ok1,ok2,ok3;
inline void LI()
{
	cin>>c1>>c2>>c3>>c4;
	//1
	if(c1==c3)
		cout<<1,ok1=1;
	else
		cout<<0;
	//2
	if(c2[0]==c4[0]&&c2[1]==c4[1]&&ok1)
		cout<<1,ok2=1;
	else
		cout<<0;
	//3
	char s1=c2[2],s2=c4[2];
	if((s1=='A'||s1=='B'||s1=='C')&&(s2=='A'||s2=='B'||s2=='C')&&ok2)
		cout<<1,ok3=1;
	else if((s1=='D'||s1=='F')&&(s2=='D'||s2=='F')&&ok2)
		cout<<1,ok3=1;
	else
		cout<<0;
	//4
	if(abs((s1-'A')-(s2-'A'))==1&&ok3)
		cout<<1;
	else
		cout<<0;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t=1;
//  cin>>t;
	while(t--)
		LI();//rp+=INF
	AC;
}
