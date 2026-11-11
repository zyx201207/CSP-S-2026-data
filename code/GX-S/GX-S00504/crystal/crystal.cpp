#include <bits/stdc++.h>
using namespace std;

const long long maxn=1e5+5;
long long n,m;
long long a[maxn];



int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    long long maxn=-10e12;
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++)
    {
        if(i==1)
        {
            maxn=1;
            continue;
        }
        int mm=m;
        int ans=0;
        for(long long j=i-1;j>=1;j--)
        {
            if(a[i]-a[j]<=mm)
            {
                mm-=a[i]-a[j];
                ans++;
            }
            else break;
        }
        ans++;
        if(ans>maxn) maxn=ans;
    }
    cout << maxn;
    return 0;
}

/*
nlogn
1 2 4 8 9

1004/5=200

4 5 6 8 1
1 4 5 6 8

-3 -1 2 2 7
1 1 1 1 5 5 5 5
*/
