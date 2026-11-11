#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N],b[N],c[N];
int f[N];
bool fl[5005][5005];
struct node{
	int st,id;
	node(int stt,int idd)
	{
		st=stt,id=idd;
	}
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(1<=c&&c<=10)
	{
		while(t--)
		{
			memset(a,0,sizeof a);
			memset(f,0x3f,sizeof f);
			memset(fl,0,sizeof fl);
			long long n,d,ans=0,cntmax=0,maxi=1;
			cin>>n>>d;
			for(int i=1;i<=n;i++)  cin>>a[i];
			for(int i=1;i<=n;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
//					int x=i,y=j;
//					while(x<j&&a[j]-a[x]>d)  x++;
//					while(y>i&&a[y]-a[i]>d)  y--;
//					if(x==y-1) 
//					{
//						ans++;
//						fl[i][j]=1;
//						int z=i;
//						while(z>0){
//							int xx=z;
//							while(z>0&&a[xx]-a[z]<=d)  z--;
//							if(!fl[z][j])  ans++;
//							fl[z][j]=1;
//						}
////						maxi=i;
//					}
					queue<node> q;
					q.push(node(0,i));
					int minn=INT_MAX,cnt=0;
					while(q.size())
					{
						node x=q.front();
						q.pop();
						if(x.id==j&&minn>x.st)  minn=x.st,cnt=1;
						else  if(x.id==j&&minn==x.st)  cnt++;
						int k=x.id+1;
						while(k<=j&&a[k]-a[x.id]<=d)
						{
							if(x.st+1<minn){q.push(node(x.st+1,k));}
//							q.push(node(x.st+1,k));
							k++;
						}
					}
//					if(cnt>cntmax)  cntmax=cnt,ans=1;
//					else  if(cnt==cntmax)  ans++;
					if(cnt==2)  ans++;
//					cout<<i<<" "<<j<<" "<<" "<<ans<<"\n";
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(11<=c&&c<=12)
	{
		while(t--)
		{
			memset(a,0,sizeof a);
			long long n,d;cin>>n>>d;
			for(int i=1;i<=n;i++)  scanf("%lld",&a[i]);
			long long l=a[n]-a[1],x=a[2]-a[1];
			long long y=d/x;
			if(y<=1||l<=d)  cout<<"0\n";
			else  cout<<n-y-1<<"\n";
		}
	}
	if(13<=c&&c<=14)
	{
		
	}
//	while(t--)
//	{
//		memset(a,0,sizeof a);
//		memset(b,0,sizeof b);
//		long long n,d,cnt=0,ans=0;
//		cin>>n>>d;
//		a[n+1]=a[n+2]=a[n+3]=LONG_LONG_MAX;
//		for(int i=1;i<=n;i++)
//		{
//			cin>>a[i];
//			if(a[i+2]-a[i]<=d)  b[++cnt]=i,ans++;
//		}
//		for(int i=1;i<=cnt;i++)
//		{
//			int x=b[i]-1;
//			while(x>0&&a[b[i]]-a[x]<=d)  x--;
//			int s=b[i]-x,x--;
//			while(x>0)
//			{
//				int l=x,x--;
//				while(x>0&&a[l]-a[x]<=d)  x--;
//			}
////			long long s,x=b[i]-1;
////			while(x>0&&a[x+2]-a[x]>d)  ans++,x--;
//////			while(y<=n&&a[y]-a[y-3]>d)  ans++,y++;
////			cout<<b[i]<<" "<<ans<<" "<<x<<"\n";
//		}
//		cout<<ans<<"\n";
//	}
	return 0;
}

