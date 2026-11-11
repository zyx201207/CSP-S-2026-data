//GZ-J00062 毕节七星关东辰实验学校 徐海荣搏
#include<iostream>
#define ll long long
#include<string>
#include<vector>
using namespace std;
char s[200005];
int main()
{
    ll n,x,i=0,m=0;
    char y;
    cin>>n;
    while(n--)
    {
    	cin>>x>>y;
    	m+=x;
    	for(i;i<=m;i++) s[i]=y;
	}
	ll ans=0;
	for(ll i=1,j=m;i<m/2,j>m/2;i++,j--)
	{
		if(s[i] != s[j]) ans++;
	}
	cout<<ans; 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return 0;
}
