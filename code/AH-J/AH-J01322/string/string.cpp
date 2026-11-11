#include<bits/stdc++.h>
using namespace std;
stack<char> k;
queue<char> l;
unsigned long long ans,cnt,op,b[500050];
char c[50050];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    unsigned long long a;
    string s;
    cin>>a;
    for(unsigned long long i=0;i<a;i++)
    {
		cin>>b[i]>>c[i];
		if(a%2==0)
		{
			if(i<=a/2)
			{
				for(unsigned long long j=1;j<=b[i];j++)
					l.push(c[i]);
			}
			if(i>=a/2)
			{
				for(unsigned long long j=1;j<=b[i];j++)
					k.push(c[i]);
			}
		}
		else
		{
			if(i<=a/2)
			{
				for(unsigned long long j=1;j<=b[i];j++)
					l.push(c[i]);
			}
			if(i>=a/2)
			{
				for(unsigned long long j=1;j<=b[i];j++)
					k.push(c[i]);
			}
		}	
    }
    while(!k.empty())
    {
		if(k.top()!=l.front()) ans++;
		k.pop();
		l.pop();
	}
	if(ans==0 || a%2==0) ;
	else ans++;
	cout<<ans;
	fclose(stdin);
    return 0;
}
