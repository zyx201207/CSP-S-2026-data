#include<bits/stdc++.h>
#define lll long long
using namespace std; 
lll n,m,cnt,ans=1;
lll a[500500];
lll c[500500];
/*struct node{
	lll st,ed,len,w;
}b[500500];*/
bool flaga,flagb;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	
		if(a[i]!=i) flaga=1;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flagb=1;
	}
	if(flaga==0){
		lll j=1;
		while(m>=j&&ans<n)
		{
			m=m-j;j++;ans++;
		}
	}
	else if(flagb==0){
		lll duan=a[n]-a[n-1];
		lll j=1;
		while(m>=j*duan&&ans<n)
		{
			m=m-j*duan;j++;ans++;
		}
	}
	else {
	
	sort(a+1,a+1+n);
	lll mid=0;
	if(n%2==0) mid=n/2;else mid=n/2+1;
	lll zhun=a[mid];
//	cout<<mid<<endl;
	for(int i=mid-1;i>=1&&m>=0;i--)
	{
	//	cout<<i<<' '<<m<<' '<<a[mid]-a[i]<<endl;
		if(m>=(a[mid]-a[i]))
		{
			ans++;
			m=m-(a[mid]-a[i]);
			cnt++;
			c[cnt]=(a[mid]-a[i]);
		}
	}
	//cout<<m<<endl;
	for(int i=mid+1;i<=n;i++)
	{
		lll to=a[i]-a[i-1];
		if (m>=(ans*to))
		{
			m=m-(ans*to);
			//cout<<i<<' '<<m<<' '<<1<<endl;
			ans++;
		}
		else if(cnt==0)
		{
			if(m>=(ans*to))
			{
				m=m-(ans*to);
				//cout<<i<<' '<<m<<' '<<2<<endl;
				ans++;
			}
		}
	else	if(to*(ans-1)<=c[cnt])
		{
			m=m+c[cnt]-to*(ans-1);
			//cout<<i<<' '<<m<<' '<<3<<endl;
			cnt--;
		}
		else break;
	}}
	
	
	
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
