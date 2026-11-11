#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2;
int n,m;
char c,d;
main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		n=(s1[0]-'0')*10+(s1[1]-'0');
		m=(s2[0]-'0')*10+(s2[1]-'0');
		if(n==m) cout<<'1';
		else cout<<"000",exit(0);
		c=s1[2],d=s2[2];
		if((c=='A'||c=='B'||c=='C')&&(d=='F'||d=='D')) cout<<'0';
		else if((d=='A'||d=='B'||d=='C')&&(c=='F'||c=='D')) cout<<'0';
		else cout<<'1';
		if(c=='A'&&d=='B'||d=='A'&&c=='B'||c=='B'&&d=='C'||d=='B'&&c=='C'||c=='D'&&d=='F'||d=='F'&&c=='D') cout<<'1';
		else cout<<'0';
	}
	else{
		cout<<"000";
		if(c=='A'&&d=='B'||d=='A'&&c=='B'||c=='B'&&d=='C'||d=='B'&&c=='C'||c=='D'&&d=='F'||d=='F'&&c=='D') cout<<'1';
		else cout<<'0';
	}
}
