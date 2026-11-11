#include <bits/stdc++.h>
using namespace std;
int n;
long long q,sum,x;
char c,h,t;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		while(x--)
		{
			s[++q]=c;
		}
	}
	for(int i=1;i<=q/2;i++){
		if(s[i]!=s[q-i+1])sum++;
	}
	cout<<sum;
	return 0;
}
