#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+5;
int n;
int a[N],la[N],p,ra[N],q;
char c[N],lc[N],rc[N];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	
	int cnt=0;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		if(f&&a[i]) ra[++q]=a[i],rc[q]=c[i];
		else
		{
			cnt+=a[i];
			if(cnt>=sum/2)
			{
				int t=cnt-sum/2;
				la[++p]=a[i]-t;
				lc[p]=c[i];
				for(int j=i-1;j>=1;j--) la[++p]=a[j],lc[p]=c[j];
				
				if(sum&1) t--;
				if(t>0) ra[++q]=t,rc[q]=c[i];
				if(t==-1) a[i+1]--;
				f=1;
			}
		}
	}
	
//	for(int i=1;i<=p;i++) cout<<la[i]<<' '<<lc[i]<<'\n';
//	cout<<'\n';
//	for(int i=1;i<=q;i++) cout<<ra[i]<<' '<<rc[i]<<'\n';
	
	int ans=0,i=1,j=1;
	while(1)
	{
		if(i>p||j>q) break;
		
		if(lc[i]!=rc[j])
		{
			if(la[i]>ra[j]) la[i]-=ra[j],ans+=ra[j++];
			else if(la[i]<ra[j]) ra[j]-=la[i],ans+=la[i++];
			else ans+=la[i++],j++;
		}
		else
		{
			if(la[i]>ra[j]) la[i]-=ra[j++];
			else if(la[i]<ra[j]) ra[j]-=la[i++];
			else i++,j++;
		}
	}
	
	cout<<ans;

	return 0;
}
/*
4
1 a
3 b
1 c
2 a
*/
