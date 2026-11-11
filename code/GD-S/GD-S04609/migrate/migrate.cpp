#include <bits/stdc++.h>
using namespace std;
int c,t,n,num,l[2000010];
long long d,x[2000010];
bool impossible[2000010];
void csh()
{
	for(int i=1;i<=2000005;i++)
		impossible[i] = false;
}
void dy()
{
 	for(int i=1;i<=n;i++)
 		cin >> x[i];
}
void cd()
{
 	for(int i=2;i<=n;i++)
 	{
 		l[i-1] = x[i] - x[i-1];
 		if (l[i-1] > d) impossible[i-1] = true;
	}
}
bool pd(int a,int b)
{
	for(int i=a;i<b;i++)
		if (impossible[i]) return true;
	return false;
}
void ns()
{
	for(int i=1;i<n;i++)
	{
		if (impossible[i]) continue;
		for(int j=i+d+1;j<=n;j++)
		{
			if (pd(i+1,j)) break;
			if (d % 2 == 1 && (j-i) % 2 == 0) continue;
			if (d % 2 == 0 && (j-i+1) % 2 == 1) continue;
			num++;
		}
	}
	
}
int main()
{
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	cin >> c >> t;
 	for(int i=1;i<=t;i++)
 	{
 		csh(); 
 		cin >> n >> d;
 		dy();
 		cd();
 		num = 0;
 		ns();
 		cout << num << endl;
	 }
 	return 0;
}
