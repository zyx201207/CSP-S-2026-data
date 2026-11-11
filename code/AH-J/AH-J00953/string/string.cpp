#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,cnt=0;
	char a;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>m>>a;
        while(m--)s+=a;
    }
    for(int i=0,j=s.size();i<=j;i++,j--)
    {
        if(s[i]!=s[j])cnt++;
    }
    cout<<cnt;
	return 0;
}
