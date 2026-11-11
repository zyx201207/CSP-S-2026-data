#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void fre()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
const int MAXN=2e5+10;
int T,a[MAXN],pos[MAXN];
ll pre[MAXN];
ll len,ans;
char c[MAXN];
int main()
{
	fre(); 
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>a[i]>>c[i];
		pre[i]=pre[i-1]+a[i];
		len+=a[i];
	}
	ll pos=1,poss=T,pr=0,prr=len;
	while(pos<=T/2&&poss>=T/2)
	{
		if(c[pos]==c[poss])
		{
			
			if(pre[pos]-pr>prr-pre[poss-1])
			{
				poss--;
				prr-=a[pos];
				pr+=prr-pre[poss-1];
			}
			else if(pre[pos]-pr<prr-pre[poss-1])
			{
				pos++;
				pr+=a[pos];
				prr-=pre[pos]-pr;
			}
			else 
			{
				pr=pre[pos];
				prr=pre[poss-1]+1;
				pos++;
				poss--;
				
			}
			
			continue;
		}
		if(pre[pos]-pr>prr-pre[poss-1])
		{
			ans+=prr-pre[poss-1];
			ll delta=prr-pre[poss-1];
			prr-=delta;
			pr+=delta;
		}
		else {
			ans+=pre[pos]-pr;
			ll delta=pre[pos]-pr;
			prr-=delta;
			pr+=delta;
		}
		if(pr>=pre[pos])
		{
			pos++;
		}
		if(prr<=pre[poss-1])
		{
			poss--;
		}
		//cout<<pos<<" "<<poss<<" "<<pr<<" "<<prr<<endl;
	}
	cout<<ans;
	return 0;
}
