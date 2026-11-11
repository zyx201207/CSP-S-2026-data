#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N=2e5+10;
string s1="",s2="";
int n,a[N],cnt1,cnt2,cnt3;
long long len,mid,tot1,tot2,pos1,pos2,sum[30],maxn=-1,f[2005][2005];
char c[N],old;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
		if(c[i]==c[i-1]) cnt1++;
		if(a[i]==1) cnt2++;
		if(c[i]!=c[i-1]) cnt3++;
		sum[c[i]-'a'+1]+=a[i];
		len+=a[i];
	}
	if(n==1){printf("0");return 0;}
	if(cnt1==n-1){printf("0");return 0;}
	if(cnt2==n){printf("%lld",len-1);return 0;}
	if(n==2||cnt3==2)
	{
		for(int i=1;i<=26;i++) maxn=max(maxn,sum[i]);
	    printf("%lld",len-maxn);
	    return 0;
	}
	if(cnt3==n){printf("%lld",len-1);return 0;}
	/*mid=(len+1)/2;
	for(int i=1;i<=n;i++)
	{
		tot1+=a[i];
		if(tot1>mid){pos1=i;break;}
	}
	tot2=tot1-mid;
	for(int i=pos1+1;i<=n;i++)
	{
		tot2+=a[i];
	}*/
	for(int i=1;i<=n;i++) for(int j=1;j<=a[i];j++) s1+=c[i];
	for(int i=len-1;~i;i--) s2[n-i]=s1[i];
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=max(f[i-1][j],f[i][j-1]);
		}
	}
	printf("%lld",len-f[len][len]);
	return 0;
}
