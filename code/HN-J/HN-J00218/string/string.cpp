#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	vector<char> c(n+1);  
	vector<int> l(n+1,0);
	long long len=0;
	for(int i=1;i<=n;++i)
	{
		cin>>l[i]>>c[i];
		len+=l[i];
	}
	
	long long ans=0;
	int i=1,j=n;
	while(i<j)
	{
		char ci=c[i];
		char cj=c[j];
		int li=l[i];
		int lj=l[j];
		
		if(li==lj)
		{
			if(ci!=cj)
			{
				ans+=li;
			}
			i++,j--;
		}
		else if(li>lj)
		{
			if(ci!=cj)
			{
				ans+=lj;
				l[i]-=lj;
				j--;
			}
			else
			{
				l[i]-=lj;
				j--;
			}
		}
		else if(li<lj)
		{
			if(ci!=cj)
			{
				ans+=li;
				l[j]-=li;
				i++;
			}
			else
			{
				l[j]-=li;
				i++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
