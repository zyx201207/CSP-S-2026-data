#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=5e5+5;

int n,m;
int a[N],s[N];
int maxans=1;

inline int cost(int x,int g){
    return a[g]*(g-x)-(s[g-1]-s[x-1]);
}

signed main()
{
    //freopen("crystal4.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    //cout <<"n="<<n <<" m="<<m<<endl;
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){s[i]=s[i-1]+a[i];}
    //cout <<"n="<<n <<" m="<<m<<endl;
    for(int i=1;i<=n;){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)/2;
            //cout << "[debug] try:" << i << ' ' << l << ' ' << r << ' ' << cost(mid,i) << endl;
            if(cost(mid,i)>m){l=mid+1;}
            else{r=mid;}
        }
        int tot=i-l+1;
        //cout << "[debug] res:" << i << ' ' << l << ' ' << r << ' ' << tot << ' ';cout << "m=" << m;
        while(a[i]==a[i+1]){i++;tot++;}
        //cout << tot << endl;
        maxans=max(tot,maxans);
        i++;
    }

    cout << maxans << endl;

    //cout << "m=" << m;

    return 0;
}
