#include <bits/stdc++.h>
using namespace std;

int a[200005];
bool cmp(int x,int y){
    int m=x,n=y;
    int p=0,q=0;
    while(x){
        if(x%2==1)
            p++;
        x/=2;
    }
    while(y){
        if(y%2==1)
            q++;
        y/=2;
    }
    if(p==q && m>n)    return m>n;
    else return p>q;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort (a+1,a+n+1,cmp);
    int cnt=0,sum=a[1];
    for(int i=2;i<=m;i++){
        sum=sum&a[i];
    }
    cout << sum;
    return 0;
}
