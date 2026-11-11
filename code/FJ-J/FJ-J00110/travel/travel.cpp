#include<bits/stdc++.h>
using namespace std;
#define int long long
#define i64 __int128_t
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii=pair<int,int>;
int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
const int mod=1e9+7;
int pows(int a,int b)
{
	int ret=1;
	while(b){
		if(b&1)ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}
void Dddd()
{
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int ok=(a1==b1);
	cout<<ok;
	if(!ok)
	{
		cout<<"000"<<endl;
		return;	
	}
	string p1=a2.substr(0,2);
	string p2=b2.substr(0,2);
	ok=(p1==p2);
	cout<<ok;
	
	if(!ok)
	{
		cout<<"00"<<endl;
		return;
	}
	
	char s1=a2[2],s2=b2[2];
	ok=((s1<=67 && s2<=67) || (s1>67 && s2>67));
	cout<<ok;
	
	if(!ok)
	{
		cout<<"0"<<endl;
		return;	
	}
	cout<<(abs(s1-s2)==1);
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int num=1;
//	cin>>num;
	while(num--)
	{
		Dddd();
	}
	return 0;
}

