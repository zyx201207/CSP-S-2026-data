//GZ-J00323 遵义航天实验中学 杨熙晨 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans[20000],len[200005];
char c[200005];
int weishu(long long n)
{
	int sum=0,sum2=0;
	for(int i=1;i<=6000;i++)
	{
		if(ans[i]>0) sum=i;
	}
	while(n/=10) sum2++;
	return max(sum,sum2);
}
void gaojingdu(long long h,int wei)
{
	int jw=0;
	for(int i=1;i<=wei+1;i++)
	{
		ans[i]=ans[i]+h%10+jw;
		jw=0;
		h/=10;
		jw=ans[i]/10;
		ans[i]%=10;
	}
	return;
}
void compare()
{
	long long l=1,r=n;
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			if(a[l]>a[r])
			{
				gaojingdu(a[r],weishu(a[r]));
				a[l]-=a[r];
				a[r]=0;
				r--;
			}
			else
			{
				gaojingdu(a[l],weishu(a[l]));
				a[r]-=a[l];
				a[l]=0;
				l++;
			}
		}
		else
		{
			if(l!=r)
			{
				if(a[l]>a[r])
				{
					a[l]-=a[r];
					a[r]=0; 
					r--;
				}
			else
				{
					a[r]-=a[l];
					a[l]=0;
					l++;
				}
			}
			else
			{
				break;
			}
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	return;
}
int main()
{
	for(int i=0;i<=20000;i++) ans[i]=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	len[0]=0;
	for(int i=1;i<=n;i++)	cin>>a[i]>>c[i];
	compare();
	for(int i=weishu(0);i>=1;i--) cout<<ans[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
