#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#define fin freopen("migrate.in","r",stdin);
#define fout freopen("migrate.out","w",stdout);
using namespace std;
typedef long long lli;
int testnum,tests,n;
lli m,ans;
lli a[2000005];
int toleft[2000005],toright[2000005];
int leftnum[2000005],rightnum[2000005];
void init()
{
    ans=0;
    for(int i=0;i<=n+1;i++)
        toleft[i]=toright[i]=leftnum[i]=rightnum[i]=0;
}
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> testnum >> tests;
    while(tests--)
    {
        cin >> n >> m;
        init();
        for(int i=1;i<=n;i++)
            cin >> a[i];

        toleft[1]=1,toright[n]=n;
        toleft[n+1]=n+1,toright[0]=0;
        for(int i=2;i<=n;i++)
        {
            toleft[i]=toleft[i-1];
            while(toleft[i]<i && a[i]-a[toleft[i]]>m)
                toleft[i]++;
        }
        for(int i=n-1;i>=1;i--)
        {
            toright[i]=toright[i+1];
            while(toright[i]>i && a[toright[i]]-a[i]>m)
                toright[i]--;
        }
        for(int i=1;i<=n;i++)
        {
            int l=toleft[i],r=min(i,toleft[i+1]);
            if(l==i || l==r)
                leftnum[i]=1;
            else
                leftnum[i]=r-l+leftnum[l];
        }
        for(int i=n;i>=1;i--)
        {
            int r=toright[i],l=max(i,toright[i-1]);
            if(r==i || r==l)
                rightnum[i]=1;
            else
                rightnum[i]=r-l+rightnum[r];
        }
        /*
        for(int i=1;i<=n;i++)
            cout << leftnum[i] << ' ';
        cout << endl;
        //*/
        for(int i=1;i<n;i++)
        {
            int j=i+1;
            int left=toleft[j],right=toright[i];
            if(left>=i || right<=j || toleft[right]<i || toright[left]>j)
                continue;
            if(toleft[j+1]<=left || toright[i-1]>=right)
                continue;
            lli vall=(toleft[i]<left?1:leftnum[left]),valr=(toright[j]>right?1:rightnum[right]);
            ans+=lli(vall+toleft[j+1]-left-1)*(valr+right-toright[i-1]-1);
            /*
            cout << "added " << lli(vall+toleft[j+1]-left-1)*(valr+right-toright[i-1]-1) << " to ans at "
                "(" << left << "," << i << "," << j << "," << right << ")\n";
            //*/
        }
        cout << ans << endl;
    }
    return 0;
}
