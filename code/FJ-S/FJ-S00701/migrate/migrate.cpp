#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int c,t,n,a[2000001],b[2000001],s[2000001],s2[2000001],ttt=0,tttt[2000001];
long long d;
vector<int>v[2000001];
struct node
{
	int id,stepp;
};
void jia()
{
	int f[2000001],tt=1,ww=1,hao=1;
	f[1]=1;
	while(1)
	{
		hao++;
		if(hao>n)
		break;
		f[ww+1]=hao;
		ww++;
		while(1)
		{
			if((s[hao]-s[t])>d)
			t++;
			else
			break;
		}
		for(int i=tt;i<ww;i++)
		{
			v[f[i]].push_back(hao);
		}
		while(!v[hao].empty())
		{
			v[hao].pop_back();
		}
	}
}
long long zou(int shou)
{
	long long cntt2=0;
	int viss[n-shou+1]={0},viss2[n-shou]={0};
	queue<node>q;
	q.push({shou,1});
//	cout<<viss[4]<<"@#$"<<endl;
	while(!q.empty())
	{
		node f=q.front();
		q.pop();
		if(viss[f.id-shou])
		{
//			cout<<f.id<<"!!!"<<viss[f.id-shou]<<endl;
			if(f.stepp>viss2[f.id-shou])
			{
//				cout<<"YYY"<<endl;
			continue;
		}
//			cout<<shou<<" "<<f.id<<" "<<f.stepp<<endl;
			viss[f.id-shou]++;
			if(viss[f.id-shou]==2)
			{
				cntt2++; 
			}
			else
			if(viss[f.id-shou]==3)
			{
				cntt2--;
			}
			for(int i=0;i<v[f.id].size();i++)
		{
			q.push({v[f.id][i],f.stepp+1});
		}
		continue;
		}
//		cout<<shou<<" "<<f.id<<" "<<f.stepp<<endl;
		viss[f.id-shou]=1;
		viss2[f.id-shou]=f.stepp;
		for(int i=0;i<v[f.id].size();i++)
		{
			q.push({v[f.id][i],f.stepp+1});
//			cout<<"!!"<<endl;
		}
	}
	return cntt2;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		if(c==11||c==12)
		if((a[2]-a[1])>d)
		cout<<0<<endl;
		else
		{
			int ge=d/(a[2]-a[1]);
			if(ge==1)
			cout<<0<<endl;
			else
			if(ge==2)
			cout<<max(0,n-3+1)<<endl;
			else
			cout<<0<<endl;
		}
		else
		{
		b[1]=0;
		for(int i=2;i<=n;i++)
		{
		b[i]=a[i]-a[i-1];
	}
		s[1]=0;
		for(int i=2;i<=n;i++)
		s[i]=b[i]+s[i-1];
		jia();
		long long cntt=0;
		for(int i=1;i<=n;i++)
		{
			cntt+=zou(i);
		}
		cout<<cntt<<endl;
		}
	}
	return 0;
 } 
