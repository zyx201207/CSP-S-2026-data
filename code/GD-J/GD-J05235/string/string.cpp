#include<bits/stdc++.h>
using namespace std;

const int N=1e6;

long long ls[N],n,ans=0;
unsigned long long alll=0;
char ho[N];

int main()
{
	cin.tie(0);
ios::sync_with_stdio(0);
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);

cin>>n;
for(long long i=0;i<n;i++)
{
	cin>>ls[i];
	cin>>ho[i];
	alll+=ls[i];
} 

long long hlhe,tll=0;
if(n%2)
for(long long i=0,tal=(alll+1)/2;i<n;i++)
{
	tll+=ls[i];
	if(tll>=tal)
	{
		hlhe=i;
		if(ls[hlhe]%2)
		{
			if((tal-tll+ls[hlhe])==(ls[hlhe]+1)/2)
			ls[hlhe]=0;
			else
			ls[hlhe]-=min((tal-(tll-ls[hlhe])),tll-tal);
		}
		else
		{
		ls[hlhe]-=min((tal-(tll-ls[hlhe])),tll-tal);
		}
		break;
	}
} 

//cout<<n<<"\n"; 
//for(long long i=0;i<n;i++)
//{
//	cout<<ls[i]<<" "<<ho[i]<<" "<<i<<"\n";
//} 

for(long long j=n-1,i=0;i<=n;i++)
{
	while(ls[i]>0)
	{
		while((ho[i]==ho[j])&&(ls[i]>0))
		{
		long long t=min(ls[i],ls[j]);
		ls[i]-=t;
		ls[j]-=t;
		if((ls[j]==0)&&((ls[i]>0)))
			{
			j--;
			}
		}
		
		while((ho[i]!=ho[j])&&ls[i]>0)
		{
		long long t=min(ls[i],ls[j]);
		ls[i]-=t;
		ls[j]-=t;
		ans+=t;
		if((ls[j]==0)&&((ls[i]>0)))
			{
			j--;
			}
		}
	}
}



cout<<ans;
//cout<<"\n"<<hlhe;
return 0;	
}
