#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long a[200020];
char c[200020];
long long cnt[1010];
long long sum[30][200020][3];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	long long len=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long lt=1;
	for(long long i=1;i<=n;i++)
	{
		long long rt=lt+a[i]-1;
		cnt[c[i]-'a'+1]++;
		sum[c[i]-'a'+1][cnt[c[i]-'a'+1]][1]=lt;
		sum[c[i]-'a'+1][cnt[c[i]-'a'+1]][2]=rt;
		lt=rt+1;
	}
	long long ans=0;
	for(long long i=1;i<=26;i++)
	{
		long long tmp=cnt[i];
		for(long long j=1;j<=cnt[i];j++)
		{
			for(long long k=tmp;k>=1;k--)
			{
				long long l=len-sum[i][j][2]+1;//4
				long long r=len-sum[i][j][1]+1;//5
				//cout<<"l="<<l<<" r="<<r<<endl;
				ans+=max(0ll,min(r,sum[i][k][2])-max(l,sum[i][k][1])+1);
				if(sum[i][k][2]<l)break;
			}
		}
		
	}
	cout<<(len-ans)/2;
	return 0;
}
/*
3
2 a
2 b
1 c

ans=2

22
2 a
3 a

ans=0

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

ans=3000000000

4796

lt1<lt<rt1<rt
pts=100
*/
