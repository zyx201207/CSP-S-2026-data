#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,m;ll minn=INT_MIN;
ll a[N];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
        return 0;
    }
    if(m==n){
        ll cnt=a[0];
        for(int i=1;i<n;i++)
        {
            cnt=(cnt&a[i]);
        }
        cout<<cnt;
        return 0;
    }
    do{
        ll cnt=a[0];
        for(int i=1;i<m;i++){
            cnt=(cnt&a[i]);
        }if(cnt>minn) minn=cnt;
    }while(next_permutation(a,a+n));
    cout<<minn;
    return 0;

}
