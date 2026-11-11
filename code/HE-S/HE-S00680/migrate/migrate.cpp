 #include<bits/stdc++.h>
 using namespace std;
 int c,t,n,d,x[2000001],way[5001][5001],num;
 int main()
 {
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	cin >> c >> t;
	while(t--)
 	{
 		bool dcsl=1;
 		cin >> n >> d;
 		cin >> x[1] >> x[2];
 		for(int i=3;i<=n;i++)
 		{
 			cin >> x[i];
 			if(x[i-1]-x[i-2]!=x[i]-x[i-1])
 			{
 				dcsl=0;
			}
		}
		if(dcsl)
		{
			if(d<x[4]-x[1]&&d>=x[3]-x[1])
			{
				if(d>=x[3])
				{
					cout << 2*n-5;
				}
				else
				{
					cout << n-3;
				}
				return 0;
			}
			else if(d>=x[3])
			{
				cout << n-2;
				return 0;
			}
		}
	return 0;
	}
 }
