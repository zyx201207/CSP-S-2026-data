# include <cstdio>
# define int long long
using namespace std;
int Tid,T,n,m,a[3000007],h1[3000007],h2[3000007],sum,le[3000007],ri[3000007];
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
void does1()
{
	for(int i=1;i<n;i++)
	{
		h1[i]=1;
		int p=le[i],q=le[i+1]-1;
		if(p>q) continue;
		h1[i]+=q-p+h1[p];
	}
}
void does2()
{
	for(int i=n;i>=2;i--)
	{
		h2[i]=1;
		int p=ri[i-1]+1,q=ri[i];
		if(p>q) continue;
		h2[i]+=q-p+h2[q];
	}
}
int read()
{
	char ch=' ';
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	int ans=0,fu=1;
	if(ch=='-') fu=-1,ch=getchar();
	while(ch>='0'&&ch<='9') ans=ans*10+ch-'0',ch=getchar();
	return ans*fu;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&Tid,&T);
	for(int happy=1;happy<=T;happy++)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++)
		{
			int l=1,r=i-1,wz=i;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(a[i]-a[mid]<=m) wz=mid,r=mid-1;
				else l=mid+1;
			}
			le[i]=wz;
			l=i+1,r=n,wz=i;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(a[mid]-a[i]<=m) wz=mid,l=mid+1;
				else r=mid-1;
			}
			ri[i]=wz;
		}
		a[0]=a[1]-m-1,a[n+1]=a[n]+m+1;
		for(int i=0;i<=n+1;i++) h1[i]=h2[i]=0;
		does1();
		does2();
		sum=0;
		for(int i=2;i<=n-2;i++)
		{
			int l1=le[i+1],r1=le[i+2]-1,l2=ri[i-1]+1,r2=ri[i];
			r1=min(r1,i-1);
			l2=max(l2,i+2);
			if(l1>r1||l2>r2) continue;
			int ans1=r1-l1+1,ans2=r2-l2+1;
			if(le[i]==le[i+1]) ans1+=h1[le[i]]-1;
			if(ri[i]==ri[i+1]) ans2+=h2[ri[i+1]]-1;
			sum+=ans1*ans2;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
