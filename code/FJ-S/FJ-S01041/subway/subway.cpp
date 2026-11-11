#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int find(vector<long long> v,int u)
{
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==u)
			return i;
	}
	return -1;
}
bool b[500005];
int main()
{ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<long long>w(m+5);
	vector<int>k(n+5);
	vector<long long> a[505];
	vector<long long> t[505];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int tt=0;
	bool f=1,ff=1;
	long long l,r;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]>2){
			ff=0;
		}
		for(int j=1;j<=k[i];j++)
		{
			cin>>l>>r;
			a[i].push_back(l);
			t[i].push_back(r);
			if(i!=1&&j!=1&&t[i][j]!=tt)
				f=0;
			tt=t[i][j];
		}
	}
	int x,y;
	long long s=0;
	if(ff==1)//A
	{
		long long s=0;
		for(int i=1;i<=q;i++)
		{
			memset(b,0,sizeof(b));
			cin>>x>>y;
			s+=w[x];//¿Ú->Ìü 
			s+=w[y];
			if((find(a[1],x)!=-1&&find(a[1],y)!=-1)||(find(a[2],x)!=-1&&find(a[2],y)!=-1))
			{
				cout<<s<<"\n";
			}
			b[x]=1;
			while(x!=y)
			{
				for(int i=1;i<=m;i++)
				{
					int h=find(a[i],x);
					if(h!=-1&&b[i]==0)
					{
						s+=t[i][0];
						s+=t[i][1];
						b[i]=1;
						if(h==0)
							x=a[i][1];
						else
							x=a[i][0];
					}
				}
				b[i]=0;
			}
			cout<<s<<endl;
		}
	}
	if(n==2)//19,20 
	{
		for(int i=1;i<=q;i++)
		{
			cin>>x>>y;
			s+=w[x];//¿Ú->Ìü 
			s+=w[y];
			if((find(a[1],x)!=-1&&find(a[1],y)!=-1)||(find(a[2],x)!=-1&&find(a[2],y)!=-1))
			{
				cout<<s<<"\n";
			}
			else
			{
				long long minn=INT_MAX;
				for(int j=0;j<a[1].size();j++)
				{
					int h=find(a[2],a[1][j]);
					if(h!=-1)
					{
						long long g=t[1][j]+t[2][h];
						minn=min(minn,g);
					}
				}
				s+=minn;
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
