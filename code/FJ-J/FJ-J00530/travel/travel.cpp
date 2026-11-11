#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
struct ff{
	ll a;
	ll b;
	ll c;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	ff n1,n2;
	string s1,s2;
	cin>>n1.a>>s1>>n2.a>>s2;
	n1.b=(s1[0]-'0')*10+s1[1]-'0';
	n2.b=(s2[0]-'0')*10+s2[1]-'0';
	n1.c=s1[2]-'A'+1;
	n2.c=s2[2]-'A'+1;
	if(n1.a==n2.a)
	{
		if(n1.b==n2.b)
		{
			if(n1.c>=4 && n2.c>=4 || n1.c<4 && n2.c<4)
			{
				if(abs(n1.c-n2.c)==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	
	return 0;
}
