#include<bits/stdc++.h>
using namespace std;
int w[100000000]={0};
int z[100000000]={0};
int t[100000000]={0};
int qi[100000]={0};
int qo[100000]={0};
int q[500]={0};
int k[500000]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int s=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int i=1;i<=2*k[i];i++)
		{
			cin>>z[i]>>t[i];
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		cin>>qi[i]>>qo[i];
		s+=w[qi[i]]+t[qi[i]]+t[qi[i]+1]+t[qi[i]+2]+w[qo[i]];
		s+=w[qi[i]]+t[qi[i]+1]+t[qo[i]]+w[qo[i]];
		if(c==0&&i==1)
		{
			cout<<s<<endl;
		}
	}
	
	return 0;
}
