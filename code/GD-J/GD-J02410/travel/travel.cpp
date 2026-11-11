#include <bits/stdc++.h>
using namespace std;
#define int long long
#define OI ios::sync_with_stdio(0);cin.tie(0)
#define end '\n'
#define pii pair<int,int>

string c1,s1,c2,s2;

bool ans[9];

inline bool check(char c)
{
	if ('A'<=c&&c<='C') return 0;
	else if ('D'<=c&&c<='E') return 1;
}

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

//	freopen("test.in","r",stdin);
	
	OI;
	
	cin>>c1>>s1>>c2>>s2;
	
	if (c1==c2) ans[1]=1;
	else ans[1]=0;
	
	string a=s1.substr(0,2),b=s2.substr(0,2);
	if (ans[1]==1&&a==b) ans[2]=1;
	else ans[2]=0;
	
	if (ans[2]==1&&check(s1[2])==check(s2[2])) ans[3]=1;
	else ans[3]=0;
	
//	cout<<s1[2]-'A'+1<<' '<<s2[2]-'A'+1<<endl;
	
	if (ans[3]==1&&( s1[2]-'A'+1+1==s2[2]-'A'+1 || s2[2]-'A'+1+1==s1[2]-'A'+1))
	{
		ans[4]=1;
	}
	else ans[4]=0;
	
	for (int i=1;i<=4;i++) cout<<ans[i];
	return 0;
}
