#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5,M=5e3+5,mod=1e9+7,INF=1e18;
string c1,s1,c2,s2,s="0000";
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		s[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			s[1]='1';
			char ch1=s1[2],ch2=s2[2];
			int w1=ch1-'A'+1,w2=ch2-'A'+1;
			if((w1<=3&&w2<=3)||(w1>=4&&w2>=4))
			{
				s[2]='1';
				if(abs(w1-w2)==1) s[3]='1';
			}
		}
	}
	cout<<s;
	return 0;
}
