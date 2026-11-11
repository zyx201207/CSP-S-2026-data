#include<bits/stdc++.h>
using namespace std;
int n,m,o,cnt1,cnt2,cnt5=1,cnt6,start=1,fan,a[200005],b[200005],l[1000005],r[1000005];
bool flag[200005];
long long ans,cnt3,cnt4;
char c,now1,now2,s[200005];
int main()
{
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	o=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=a[i];
		b[i]=a[i];
		scanf("%c",&c);
		scanf("%c",&c);
		s[i]=c;
	}
	for(int i=1;i>0;i++)
	{		
		fan=n-i+2*start-1;	
		if(m==o||fan<=0||ans==0)
		{
			break;
		}
		if(a[i]>a[fan]&&a[i]!=0&&a[fan]!=0)
		{
			if(flag[i])
			{
				ans+=l[cnt1];
				l[cnt1]=0;
				cnt1--;
			}		
			cnt1++;
			l[cnt1]=a[fan];
			ans-=l[cnt1];
			cnt1++;
			l[cnt1]=a[i]-a[fan];
			ans-=l[cnt1];
			if(!flag[fan])
			{
				cnt2++;
				r[cnt2]=a[fan];
				ans-=r[cnt2];
			}
			a[i]=l[cnt1];			
			flag[i]=1;
			a[fan]=0;
			m++;
			i--;
			n--;
		}
		else if(a[i]<a[fan]&&a[i]!=0&&a[fan]!=0)
		{
			if(flag[fan])
			{
				ans+=r[cnt2];
				r[cnt2]=0;
				cnt2--;
			}
			cnt2++;
			r[cnt2]=a[i];
			ans-=r[cnt2];
			cnt2++;
			r[cnt2]=a[fan]-a[i];
			ans-=r[cnt2];
			if(!flag[i])
			{
				cnt1++;
				l[cnt1]=a[i];
				ans-=l[cnt1];
			}
			a[i]=0;
			m++;
			a[fan]=r[cnt2];
			flag[fan]=1;
			n--;
			start++;
		}
		else if(a[i]==a[fan]&&a[i]!=0&&a[fan]!=0)
		{
			cnt1++;
			l[cnt1]=a[i];
			ans-=l[cnt1];
			cnt2++;
			r[cnt2]=a[fan];
			ans-=r[cnt2];
			m+=2;
		}
		else
		{
			break;
		}
	}
	ans=0;
	cnt6=o;
	cnt1=min(cnt1,cnt2);
	for(int i=1;i<=cnt1;i++)
	{
		cnt3+=l[i];
		cnt4+=r[i];
		if(cnt3==b[cnt5])
		{
			cnt5++;
			cnt3=0;
		}
		if(cnt4==b[cnt6])
		{
			cnt6--;
			cnt4=0;
		}
		now1=s[cnt5];
		now2=s[cnt6];
		if(now1!=now2)
		{
			ans+=l[i];
		}
	}
	printf("%lld",ans);	
	return 0;
}
