#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m,a[500005],b[500005];
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    sort(a+1,a+1+n);

    int cnt=0,n1=2;

    for(int i=2;i<=n;i++){
        if(m>0){
            for(int j=1;j<i;j++){
                if((a[j] < a[i])&&(m-a[i]+a[j] >= 0)){
                    m -= a[i]-a[j];
                    a[j] = a[i];

                }
                else break;
            }
        }
        else break;
    }

    //for(int i=1;i<=n;i++) cout << a[i] << ' ';

    int maxn=0,maxn2=1;

    for(int i=1;i<=n;i++){
        b[a[i]]++;
        if(a[i] > maxn) maxn = a[i];
    }
    for(int i=1;i<=maxn;i++){
        if(b[i] > maxn2) maxn2 = b[i];
    }



    cout << maxn2;

    return 0;
}
