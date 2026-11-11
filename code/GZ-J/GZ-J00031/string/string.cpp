//GZ-J00031 贵阳市白云区华师一学校 李峈颐 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],a1[100005],a2[100005],kj=1,fn,i=1;
long long ans,cnt;
char c[200005],c1[200005],c2[200005];
bool f,qo;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++,kj++)
	{
		cin>>a[kj]>>c[kj];
		cnt+=a[kj];
		if(c[kj]==c[kj-1])
		{
			a[kj-1]=a[kj-1]+a[kj];
			kj--;
		}
	}
	kj--;
	if(kj==1)
	{
		cout<<0;
		return 0;
	}
	qo=false;
	if(cnt%2==0)cnt/=2,qo=true;
	else cnt=cnt/2+1;
	f=false;
	fn=0;
	for(int i=1,l=0;i<=kj;i++)
	{
		if(qo)
		{
			if(l<cnt)
			{
				if(l+a[i]>cnt)
				{
					a1[i]=cnt-l;
					fn=cnt-l;
					l+=fn;
					f=true;
				}
				else a1[i]=a[i],l+=a[i];
				c1[i]=c[i];
			}
			else if(l>cnt)
			{
				if(f)
				{
					f=false;
					a2[i]=a[i]-max(0LL,fn);
					l+=a2[i];
				}
				else a2[i]=a[i],l+=a[i];
				c2[i]=c[i];
			}
		}
		else
		{
			if(l<cnt)
			{
				if(l+a[i]>=cnt)
				{
					a1[i]=cnt-1-l;
					l+=a1[i];
					fn=a1[i];
					f=true;
				}
				else a1[i]=a[i],l+=a[i];
				c1[i]=c[i];
				f=true;
			}
			if(l==cnt-1)
			{
				l=l+2;
			}
			if(l>=cnt)
			{
				if(f)
				{
					f=false;
					a2[i]=a[i]-1-fn;
					l+=a2[i];
				}
				else a2[i]=a[i],l+=a[i];
				c2[i]=c[i];
			}
		}
	}
	long long l=0,r=0;
	for(int i=1,j=kj;i<=j;i++,j--)
	{
		if(a1[i]<=0)i++;
		else if(a2[j]<=0)j--;
		if(a1[i]==a2[j]&&c1[i]!=c2[j]&&l==r)
		{
			ans+=(long long)a1[i]; 
		}
		else if(a1[i]!=a2[j]&&c1[i]==c2[j]&&l==r)
		{
			ans+=(long long)abs(a1[i]-a2[j]); 
			if(a2[j]>a1[i])
			{
				a1[i+1]-=abs(a2[j]-a1[i]);
				l+=a2[j];
				r+=a2[j]; 
			} 
			else
			{
				a2[j-1]-=abs(a2[j]-a1[i]);
				l+=a1[i];
				r+=a1[i]; 
			}
		}
		else if(a1[i]==a2[j]&&l!=r)
		{
			ans+=(long long)abs(l-r)*2; 
		}
		else if(a1[i]!=a2[j]&&c1[i]!=c2[j]&&l==r)
		{
			ans+=(long long)max(a1[i],a2[j]);
			if(a2[j]>a1[i])
			{
				a1[i+1]-=abs(a2[j]-a1[i]);
				l+=a2[j];
				r+=a2[j]; 
			} 
			else
			{
				a2[j-1]-=abs(a2[j]-a1[i]);
				l+=a1[i];
				r+=a1[i]; 
			}
		}
		else if(a1[i]!=a2[j]&&c1[i]!=c2[j]&&l!=r)
		{
			ans+=(long long)max(a1[i],a2[j]); 
			if(a2[j]>a1[i])
			{
				a1[i+1]-=abs(a2[j]-a1[i]);
				l+=a2[j];
				r+=a2[j]; 
			} 
			else
			{
				a2[j-1]-=abs(a2[j]-a1[i]);
				l+=a1[i];
				r+=a1[i]; 
			}
		}
		else if(a1[i]!=a2[j]&&c1[i]==c2[j]&&l!=r)
		{
			ans+=(long long)abs(a1[i]-a2[j]); 
			if(a2[j]>a1[i])
			{
				a1[i+1]-=abs(a2[j]-a1[i]);
				l+=a2[j];
				r+=a2[j]; 
			} 
			else
			{
				a2[j-1]-=abs(a2[j]-a1[i]);
				l+=a1[i];
				r+=a1[i]; 
			}
		}
	}
	cout<<ans;
	return 0;
 } 
