//GZ-S00005 ²ÜÓşèñ
#include<bits/stdc++.h>
using namespace std;
int c,t,a[20005],b[20005],cnt,n,d,ans;
int f(int i,int j)
{
	int as=0;
	for(int p=i; p<j; p++){
	for(int q=p+1;q<=j; q++){
	int an=1,c[5],cnt=0;
	for(int k=p; k<=q; k++)
	{
		if(a[k+1]-a[k]+cnt<=d)
		{
			cnt+=a[k+1]-a[k];
		}
		else
		{
			c[an]=k-c[an-1];
			an++;
			cnt=a[k+1]-a[k];
			if(an>2)
			{
			    break;
			}
		}
	}
	   if(an==2 && c[1]!=c[2])
		  as++;
    }
    }
    return as;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1; i<=n; i++)
		{
			cin >> a[i];
			if(a[i]-a[i-1]>d)
			{
				ans+=f(cnt,i);
				cnt=i+1;
				b[i]=0;
			}
			else   b[i]=b[i-1]+a[i];
		}
		cout << ans << endl;
		ans=0;
	}
	return 0;
}
