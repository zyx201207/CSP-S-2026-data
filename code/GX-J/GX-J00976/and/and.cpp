#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    int ans=0;
    for (int bit = 30; bit >= 0; bit--)
    {
        int candidate = ans | (1 << bit);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if ((a[i] & candidate) == candidate) 
				cnt++;
        if (cnt >= m) 
			ans = candidate;
    }
    
    cout << ans;
    return 0;
}
