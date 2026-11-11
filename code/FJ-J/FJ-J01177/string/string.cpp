#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,len,a[200010];
char c[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
		//cout<<"reading"<<len<<endl;
	}
	//cout<<s<<endl;
	ll i=0,atpara=0,atcnt=0,j=len-1,atparj=n-1,atcnj=0;
	while(i<(len%2?len/2:len/2))
	{
		cout<<i<<' '<<atpara<<' '<<atcnt<<' '<<j<<' '<<atparj<<' '<<atcnj<<endl;
		ll run=abs(min(a[atpara]-atcnt,a[atparj]-atcnt));
		if(c[atpara]!=c[atparj])ans+=run;
		cout<<run<<endl;
		i+=run;atcnt+=run;atcnj+=run;j-=run;
		if(atcnt>=a[atpara])
		{
			atcnt=atcnt-a[atpara];
			atpara++;
		}
		if(atcnj>=a[atparj])
		{
			atcnj=atcnj-a[atparj];
			atparj--;
			
		}
	}
	cout<<ans;
	return 0;
}
