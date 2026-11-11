//GZ-S00281 遵义航天高级中学 罗上 
#include <iostream>
#include <fstream>
using namespace std;
int x[2000005];
int count[2000005];
int main()
{
	ifstream in("migrate.in",ios::in);
	ofstream out("migrate.out",ios::out);
	int c,t;
	in>>c>>t;
	cout<<1;
	for(int z=0;z<t;z++)
	{
		int n,d,ans=0;
		in>>n>>d;
		d*=2;
		for(int i=0;i<n;i++)
		{
			in>>x[i];
		}
		cout<<1;
		int l=0,r=0,num=0;
		while(r<n)
		{
			if(num<=d)
			{
				cout<<1;
				if(r-l==3)
				{
					ans++;
				}
				r++;
				cout<<1;
				num+=x[r]-x[r-1];
			}
			else
			{
				l++;
				num-=x[l]-x[l-1];
			}
		}
		cout<<1;
		out<<ans<<'\n';
	}
	in.close();
	out.close();
}

