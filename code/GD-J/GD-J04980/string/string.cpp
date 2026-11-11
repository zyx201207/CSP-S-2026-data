#include<bits/stdc++.h>
using namespace std;
vector<int> chuan1;
vector<char> chuan2;
long long n=0,ans=0;
long long zhui[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	chuan1.resize(n+1);
	chuan2.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>chuan1[i]>>chuan2[i];
		zhui[i]=zhui[i-1]+chuan1[i];
	}
	long long l=0,r=0,shu=0;
	for(int i=1;i<=n;i++)
	{
		if(zhui[i-1]<=zhui[n]/2&&zhui[i]>=zhui[n]/2)
		{
			l=i-1;
			r=i;
			shu=zhui[n]/2-zhui[i-1];
			break;
		}
	}
	long long tmp=0;
	char tmp2;
	if(shu!=0)
	{
		tmp=chuan1[r]-shu;
		tmp2=chuan2[r];
		chuan1.insert(chuan1.begin()+r,shu);
		chuan1.insert(chuan1.begin()+r+1,tmp);
		chuan1.erase(chuan1.begin()+r+2); 
		chuan2.insert(chuan2.begin()+r,tmp2);
	}
	l++;
	r++;
	while(l>0&&r<=n+1)
	{
		if(chuan1[l]>chuan1[r])
		{
			chuan1[l]=chuan1[l]-chuan1[r];
			if(chuan2[l]!=chuan2[r])
			{
				ans=ans+chuan1[r];
			}
			r++;
		}
		else
		{
			chuan1[r]=chuan1[r]-chuan1[l];
			if(chuan2[l]!=chuan2[r])
			{
				ans=ans+chuan1[l];
			}
			l--;
		}
	}
	cout<<ans;
	return 0;
}
