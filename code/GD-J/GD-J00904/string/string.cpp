#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N  = 2e5 + 74;
int n , a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
    ll sum = 0;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i],sum+=a[i];
    int r=n,l=1,s=0,rp=0,lp=0;//rp=inf?.
    int ans=0;
    while(l<r)
    {
        if(c[r]==c[l])
        {
            if(a[r]==a[l])
            {
                r--,l++;
            }else if(a[r]>a[l])
            {
                a[r]-=a[l];
                l++;
            }else{
                a[l]-=a[r];
                r--;
            }
            //continue ;
        }else
        {
            if(a[r]==a[l])
            {ans+=a[r];
                r--,l++;
            }else if(a[r]>a[l])
            {
                a[r]-=a[l],ans+=a[l];
                l++;
            }else{
                a[l]-=a[r],ans+=a[r];
                r--;
            }
        }
        //cout<<a[l]<<' '<<a[r]<<' '<<l<<' '<<r<<'\n';
    }
    cout << ans;
	return 0;
}

