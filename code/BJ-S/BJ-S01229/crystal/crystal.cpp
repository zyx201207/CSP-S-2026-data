#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int c[500100];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        int s;
        cin >> s;
        c[i] = s;
    }
    sort(c,c+n);
    for(int i=0 ; i<n-1 ; i++)
    {
        int x=c[i+1]-c[i];
        int tmp=1;
        int j=i+1;
        while(x <= m && j<n)
        {
            x += (c[j+1] - c[j])*(j-i);
            j++;
            tmp++;
        }
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}


