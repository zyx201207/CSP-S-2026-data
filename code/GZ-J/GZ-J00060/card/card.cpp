//GZ-J00060  务川仡佬族苗族自治县县庆中学 田星辰 
#include<bits/stdc++.h>
using namespace std;
stack <int>s;
int n,m,a[100086],b[100086],c[100086],d[100086];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			s.push(a[j]);
			b[a[j]]++;
			if(b[a[j]]==2)
			{
				b[a[j]]=1;
				for(int k=c[a[j]];k<j;k++) s.pop();
			}
			c[a[j]]=j;
		}
		for(int j=1;j<=s.size();j++)
		{
			d[s.top()]++;
			s.pop();
		}
	}
	d[1]++;
	for(int i=1;i<=m;i++) cout << d[i] <<" ";
	return 0;
	fclose(stdin);
	fclose(stdout);
}


