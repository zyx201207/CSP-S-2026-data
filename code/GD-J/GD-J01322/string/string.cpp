#include<bits/stdc++.h>
using namespace std;
long long a,n,las,ans,las2,las3;
long long m,l,q,hal,mm,al;
char c;
long long ch[200005][5];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=n+1;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		while(1)
		{
			scanf("%c",&c);
			if(c!='\n'&&c!=' '&&c!='\r') break;
		}
		ch[i][0]=a;
		ch[i][1]=int(c);
		ch[i][2]=las+1;
		ch[i][3]=las+a;
		las+=a;
	}
	hal=las/2;
	al=las;
	las=0;
	for(int i=1;i<=n;i++)
	{
		m=min(ch[i][3],hal);
		mm=min(ch[i][2],hal);
		if(ch[i][2]>hal)
		{
			break;
		}
		q=i;
		las2=mm;
		while(1)
		{
			if(l==0) break;
			las=max(al-ch[l][3]+1,mm);
			las3=min(al-ch[l][2]+1,m);
			if(m<las)
			{
				l--;
				continue;
			}
			if(ch[i][1]==ch[l][1])
			{
				if(al-ch[l][2]+1>=m)
				{
					break;
				}
				else
				{
					l--;
				}
				continue;
			}
			else
			{
				ans+=las3-las+1;
			}
			if(al-ch[l][2]+1>m)
			{
				break;
			}
			if(al-ch[l][2]+1==m)
			{
				l--;
				break;
			}
			l--;
		}
	}
	cout<<ans;
	return 0;
}
