#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[2000005];
	long long T,cd=0,ans=0,max_n,max_ai;
	long long n;
	char c;
	cin>>T;
	while(T--)
	{
		cin>>n>>c;
		for(int i=0;i<n;i++)
		{
			s[cd]=c;
			cd++;
		}
	}
	//for(int i=0;i<cd;i++)cout<<s[i];
	//cout<<"cd="<<cd<<endl;
	for(int i=0;i<cd/2;i++)
	{
		if(s[i]!=s[cd-i-1])
		{
			ans++;
			//cout<<"i="<<i<<" cd-i-1="<<cd-i-1<<" s[i]="<<s[i]<<" s[cd-i-1]="<<s[cd-i-1]<<endl;
		}
	}
	cout<<ans;
	return 0;
}

