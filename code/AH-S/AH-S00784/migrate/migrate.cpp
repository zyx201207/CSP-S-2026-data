#include<bits/stdc++.h>
using namespace std;
long long cnt,Min=0x3f3f3f3f3f3f3f3f,ans,d;
long long a[2000005];
void fin(int x,int y,long long ste)
{
	if (x==y && ste==Min)
	{
		ans++;
		return;
	}
	if (x==y && ste<Min)
	{
		Min=ste;
		ans=1;
		return;
	}
	if (ste>Min) return;
	for (int i=x+1;i<=y;i++)
		if (a[i]-a[x]<=d)
			fin(i,y,ste+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cnt=0;
		int n;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		for (int i=1;i<n-1;i++)
		{
			for (int j=i+2;j<=n;j++)
			{
				if (a[j]-a[i]<=d || a[j]-a[j-1]>d || a[i+1]-a[i]>d) continue;
				ans=0,Min=0x3f3f3f3f3f3f3f3f;
				fin(i,j,0);
				if (ans==2)
					cnt++;
			}	
		}
		cout<<cnt<<endl;
	}
	return 0;
}
//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6

