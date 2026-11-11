#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string a,b,c,d;
int ans[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	
	int sa=a.size();
	int sb=b.size();
	
	if(a==c)ans[1]=1;
	else 
	{
		cout<<"0000";
		return 0; 
	} 
	
	if(ans[1]&&b[0]==d[0]&&b[1]==d[1])ans[2]=1;
	
	if(ans[2]&&((b[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&(d[2]=='A'||d[2]=='B'))||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')))
	{
		ans[3]=1;
	}
	
	if(ans[2]&&((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')))
	{
		ans[4]=1;
	}
	
	for(int i=1;i<=4;i++)cout<<ans[i];
	
	return 0;
}

