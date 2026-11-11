#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;
    if(!(cin>>n>>m)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<long long> pref(n+1,0);
    for(int i=0;i<n;i++)
    {
        pref[i+1]=pref[i]+a[i];
    }
    int maxc=0;
    int l=0;
    for(int r=0;r<n;r++)
    {
        while(1){
            long long len=r-l+1;
            long long sum=pref[r+1]-pref[l];
            long long cost=len*a[r]-sum;
            if(cost<=m){
                maxc=max(maxc,int(len));
                break;
            }
            else
                l++;
         }
    }
    cout<<maxc;
    return 0;
}
