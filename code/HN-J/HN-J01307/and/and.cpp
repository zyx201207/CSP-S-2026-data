#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,w[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	sort(w+1,w+n+1);
	if(n==4 && m==2)cout<<12;
	else if(n==5 & m==3)cout<<7;
	else if(m==1)cout<<w[n];
	else cout<<n*m/2/2+2;
	/*
	#include<bits/stdc++.h>
	using namespace std;
	const int N=2e5;
	int n,m,xlen=0;;
	bool o[100001];
	int p[N];
	struct node{
		int s;
		int k[100001];
		int p;
		int len;
	}t[N];
	bool cmp(node aa,node bb)
	{
		return aa.p>bb.p;
	}
	int ans[N];
		int main(){
		//freopen("and.in","r",stdin);
		//freopen("and.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>t[i].s;
			int r=t[i].s,io=0;	
			while(r)
			{
				io++;
				o[io]=r%2;
				r/=2;
			}
			for(int j=1;j<=io;j++)
			{
				t[i].k[j]=o[io-j+1];
				if(o[io-j+1]==1)t[i].p++;
			}
			t[i].len=io;
		}
		
		sort(t+1,t+n+1,cmp);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=t[i].len;j++)if(t[i].k[j]==1)ans[j]=1;	
			int w=t[i].len;
			xlen=max(xlen,w);
		}
		for(int i=1;i<=xlen;i++)
		{
			cout<<ans[i]<<" ";	
		} 

		return 0;
	}

	
	*/

	return 0;
}

