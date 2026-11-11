#include<bits/stdc++.h>
namespace My
{
	using namespace std;
	typedef long long ll;
	const int N=2000005;
	const ll inf=(1ll<<62);
	ll d,a[N],pre[N],suf[N],ans;
	int Pl[N],Pr[N],Sl[N],Sr[N];
	int n,c,T;
	void G()
	{
		ans=0;
		for(int i=0;i<=n+1;i++)
		{
			//Clean
			pre[i]=suf[i]=a[i]=0;
			Pl[i]=Pr[i]=Sl[i]=Sr[i]=0;
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		a[0]=-inf;a[n+1]=inf;
		pre[1]=suf[n]=1;
		for(int i=2,j=0,k=0;i<=n;i++)
		{
			while(j<i&&a[i]-a[j]>d) j++;//yes
			while(k<i&&a[i+1]-a[k]>d) k++;//no
			Pl[i]=j,Pr[i]=min(k-1,i-2);
			if(j<k) pre[i]=(i-1-j)+pre[j]+1;
			else pre[i]=1;
//			cout<<pre[i]<<" ";
		}
//		cout<<".";
		for(int i=n-1,j=n,k=n;i>=1;i--)
		{
			while(j>i&&a[j]-a[i]>d) j--;
			while(k>i&&a[k]-a[i-1]>d) k--;
			Sl[i]=max(k+1,i+2),Sr[i]=j;
			if(j>k) suf[i]=(j-i-1)+suf[j]+1;
			else suf[i]=1;
//			cout<<suf[i]<<" ";
		}
		for(int i=2;i<n-1;i++)
		{
			if(Pr[i+1]<Pl[i+1]||Sr[i]<Sl[i]) continue;
//			ll w=0;
			ll w=1ll*(Pr[i+1]-Pl[i+1])*(Sr[i]-Sl[i]);
//			if(Pl[i+1]==Sl[i]&&Pr[i+1]==Sr[i]) 
			w+=suf[Sr[i]]*pre[Pl[i+1]];
			ans+=w;
		}
		cout<<ans<<"\n";
	}
	int main()
	{
//		system("fc migrate.out migrate4.ans");return 0;
//		freopen("migrate1.in","r",stdin);
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
		cin>>c>>T;
		while(T--) G();
		return 0;
	}
}
int main()
{
	return My::main();
}
