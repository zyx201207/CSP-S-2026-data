#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		int num;
		char ch;
		cin>>num>>ch;
		while(num--)
			a+=ch;
	}
	int len=0;
	for(int i=a.size()-1;i>a.size()/2;i--)
		if(a[len++]!=a[i]) cnt++;
	cout<<cnt;
	return 0;
}
