#include<bits/stdc++.h>
#define iu long long
using namespace std;
iu c,t,n,d,a[2000010],f[2000010],flg,pik=-1;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int rty=1;rty<=t;rty++)
	{
		cin>>n>>d;
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		f[1]=0;
		int ceshi=0;
		for(int i=2;i<=n;i++)
		{
			
			for(int j=1;j<=d;j++)
			{
				//cout<<' '<<i<<' '<<j<<'\n';
				if(i-j<=0)
				{
					//cout<<'x'<<'\n';
					break;
				}
				if(f[i]==f[i-j]+1&&flg)
				{
					ceshi+=n-i+1;
					flg=0;
					pik=i;
					//cout<<'y'<<' '<<ceshi<<'\n';
					continue;
				}else if(flg==0&&f[i]==f[i-j]+1){
					ceshi=0;
				}else{
					flg=1;
				}
				//cout<<"or ";
				if(f[i]>f[i-j]+1)
				{
					//cout<<'z'<<' '<<f[i-j]+1<<' '<<f[i]<<' ';
					f[i]=f[i-j]+1;
					if(pik==i)
					{
						ceshi=0;
					}
					//cout<<f[i]<<'\n';
				}
			}
		}
		cout<<ceshi<<'\n';
	}
	return 0;
}
