#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000001],b[10000001];
int main()
{
	freopen("card3.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	if(m==1)
	{
        cout << n;
	    return 0;
	}
	int s[m+1];
	for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            for(int k=1; k<=j; k++)
                if(a[j]==b[k])
                {
                    for(int f=1; f<=k; f++)
                        b[f]=0;
                }
            b[j]=a[j];
        }
        for(int j=i; j<=n; j++)
            for(int k=1; k<=m; k++)
                if(b[j]==k)
                    s[k]++;
    }
    for(int i=1; i<=n; i++)
        cout << s[i] << " ";
    return 0;
}
