#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("ctrystal.in","r",stdin);
	freopen("ctrystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	char c[n];
	for(int i=0;i<n;i++) cin >> c[i];
	int o;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(c[j]>c[j+1]){
				o=c[j];
				c[j]=c[j+1];
				c[j+1]=o;
			}	
		}
	}
	int w=1;
	int y=0;
	for(int i=0;i<n;i++)
	{
		if(c[n/2]>c[i]||c[n/2+1]>c[i])
		{
			for(y;y<m;y++)
			{
				if(c[n/2]>=c[i]) 
				{
					c[i]=c[i]+1;
				}
			}
		}
		if(c[n/2]==c[i]||c[n/2+1]==c[i]) w++;
	}
	cout << w << endl;
	return 0;
}
