#include<bits/stdc++.h>
using namespace std;
long long n,a,ge,ans;
char c;
struct a
{
	long long chang;
	char zhi;
}chuan[200001];
void zhao(long long wei)
{
	long long qian=0,hou=0,sheng=0,qg=1,hg=n;
	while(qian+chuan[qg].chang<=(ge+1)/2&&hg!=qg)
	{
		if(chuan[qg].zhi!=chuan[hg].zhi)
		{
			ans+=min(chuan[qg].chang,chuan[hg].chang);
		}
		qian+=min(chuan[qg].chang,chuan[hg].chang);
		hou+=min(chuan[qg].chang,chuan[hg].chang);
		if(chuan[qg].chang>chuan[hg].chang)
		{
			chuan[qg].chang-=chuan[hg].chang;
			hg-=1;
		}
		else if(chuan[qg].chang==chuan[hg].chang)
		{
			hg-=1;
			qg+=1;
		}
		else
		{
			chuan[hg].chang-=chuan[qg].chang;
			qg+=1;
		}
	}
	
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a>>c;
    	ge+=a;
    	chuan[i].chang=a;
    	chuan[i].zhi=c;
	}
	zhao(1);
	cout<<ans;
	return 0;
 } 
