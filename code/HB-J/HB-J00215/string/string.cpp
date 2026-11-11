#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	while(n--)
	{
		int q;
		char a;
		scanf("%d",&q);
		cin>>a;
		while(q--)s+=a;
	}
	int ss=int(s.length()),ans=ss/2;
	for(int i=0;i<ss/2;i++)
		if(s[i]==s[ss-1-i])
			ans--;
	cout<<ans;
	return 0;
}
