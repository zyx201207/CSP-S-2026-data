#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	string s;
    int n,anns=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		int a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s[anns]=b;
			anns+=1;
		}
	}
    int ans=0;
    for(int i=0;i<anns;i++)
    {
		if(s[i]!=s[anns-i-1]) ans+=1;
	}
	cout<<ans/2;
    return 0;
}
