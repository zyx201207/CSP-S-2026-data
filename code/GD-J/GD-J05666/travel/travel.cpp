#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c1,c2,o=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		o++;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&o==0){
		cout<<1;
	}
	else{
		cout<<0;
		o++;
	}
	int w1,w2;
	w1=s1[2]-'A';
	w2=s2[2]-'A';
	if(w1<=2&&w2<=2&&o==0||w1>2&&w2>2&&o==0)
	{
		cout<<1;
	}
	else{
		cout<<0;
		o++;
	}
	if(w1-1==w2&&o==0||w1+1==w2&&o==0)
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
