#include<bits/stdc++.h>
typedef long long ll;
ll c,t,n,d,x[2000010],minlen,mincnt;
using namespace std;
void seelen(ll first,ll from,ll to,ll flewlen)
{
	if(flewlen>=minlen&&from!=to)return;
	if(from==to)
	{
		if(flewlen==minlen)
		{
			//cout<<"first "<<first<<"to "<<to<<"has a min at "<<flewlen;
			mincnt++;
		}
		else if(flewlen<minlen)
		{
			//cout<<"first "<<first<<"to "<<to<<"has a ///new/// min at "<<flewlen;
			minlen=flewlen;
			mincnt=1;
		}
		//cout<<"reach"<<to<<endl;
		return;
	}
	//cout<<from<<' ';
	int i=to;
	while(x[i]-x[from]>d)i--;
	for(;i>=0;i--)seelen(first,i,to,flewlen+1);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>t;
	ll sjdcnt=0;
	for(int eriughguhirrgeuhia=0;eriughguhirrgeuhia<t;eriughguhirrgeuhia++)
	{
		sjdcnt=0;
	//	cout<<"qqqqqqqq"<<eriughguhirrgeuhia<<"qqqqqqqq"<<endl<<endl;
		cin>>n>>d;
		for(int i=0;i<n;i++)cin>>x[i];
	//	for(int i=0;i<n;i++)cout<<x[i]<<' ';
	//	cout<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=i+2;j<n;j++)
			{
				minlen=(ll)1<<(ll)30,mincnt=0;
		//		cout<<"see"<<i<<','<<j<<endl;
				seelen(i,i,j,0);
				if(minlen!=(ll)1<<(ll)30&&mincnt==2){sjdcnt++;/*cout<<i<<' '<<j<<"ok\n";*/}
			}
		}
		cout<<sjdcnt<<endl;
	}
	return 0;
}
