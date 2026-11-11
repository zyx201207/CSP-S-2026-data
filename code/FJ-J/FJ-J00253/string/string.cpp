#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l2[100001];
	long long s=0;
	char l1[100001];
	for(int a=0;a<n;a++)
	{
		int k1;
		char k2;
		cin>>k1>>k2;
		l1[a]=k2;
		l2[a]=k1;
	}
	int t=0,w=n-1;
	while(t<w)
	{
		if(l1[t]==l1[w])
		{
			if(l2[t]>l2[w]) l2[t]-=l2[w],w--;
			if(l2[t]==l2[w]) t++,w--;
			if(l2[t]<l2[w]) l2[w]-=l2[t],t++;
		}
		else
		{
			if(l2[t]>l2[w]) s+=l2[t]-l2[w],l2[t]-=l2[w],w--;
			if(l2[t]==l2[w]) t++,w--,s+=l2[t];
			if(l2[t]<l2[w]) s+=l2[w]-l2[t],l2[w]-=l2[t],t++;
		}
	}
	cout<<s;
	return 0;
}