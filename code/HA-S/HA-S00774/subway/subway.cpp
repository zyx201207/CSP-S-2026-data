#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sum,nxt;
struct way
{
	int x,y,c;
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	way a[1000000];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x;
	}
	for(int i=1;i<=n;i++)
	{
		int w;
		cin>>w;
		for(int j=1;j<=w;j++)
		{
			int p;
			cin>>p;
			if(a[p].y==0){
				cin>>a[p].y;
			}
			else{
				cin>>a[p].c;
			}
		}
	}
	bool flag=false;
	for(int i=1;i<=q;i++)
	{
		if(flag==false){
			sum+=a[i].x;
			flag=true;
		}
		else{
			sum+=a[i].y;
			if(a[i].c!=0){
				sum+=a[i].c;
			}
		}
	}
	cout<<sum;
	return 0;
}
