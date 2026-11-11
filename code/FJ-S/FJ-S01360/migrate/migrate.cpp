#include<bits/stdc++.h>
using namespace std;
int isl[2000005];
int dis[2000005];
int t[2000005];
int t2[2000005];
long long ans;
int main()
{
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cout.tie(0);
 	int c,t1;
 	cin >> c >> t1;
 	while(t1--)
 	{
 		ans=0;
 		int n,d;
 		cin >> n >> d;
 		for(int i = 1;i<=n;i++)
 		cin >> isl[i],dis[i]=isl[i]-isl[1];
 		for(int k = 1;k<=n;k++)
 		{
 			memset(t,0x5f,sizeof(t));
 			memset(t2,0,sizeof(t2));
 			t[k]=0,t2[k]=1;
 			for(int i = k+1;i<=n;i++)
 			{
 				for(int j = i-1;j>=k;j--)
 				{
 					if(dis[i]-dis[j]<=d)
 					{
 						if(t[j]+1<t[i])
 						{
 							t[i]=t[j]+1;
 							t2[i]=t2[j];
						}
						else
						{
							if(t[j]+1==t[i])t2[i]+=t2[j];
						}
					 }
					 else
					 {
					 	break;
					 }
				 }
				 if(t2[i]==2)
				 {
				 	ans++;
				 }
			}
		 }
 		cout << ans << '\n';
	 }
 	return 0;
}

