#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long a[10000005];
bool flag = 0;
long long b[10000005],c[10000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        cnt += a[i];
    }
    long long midd = cnt/n;
    for(int i=1; i<=n; i++){
        if(a[i] == midd){
            flag = 1;
            break;
        }
    }
    for(int i=1; i<=n; i++){
        b[i] = abs(midd - a[i]);
    }
    sort(b+1,b+n+1);
    if(flag == 1){
        int last;
        int t = m;
        for(int i=1; i<=n; i++){
            if(t - b[i] <= 0){
                last = i;
                break;
            }
            t -= b[i];
        }
        cout << last;
        return 0;
    }
    else{
        for(int i=1; i<=n; i++){
            c[i] = abs(b[1] - a[i]);
        }
        int last;
        int t = m;
        for(int i=1; i<=n; i++){
            if(t - c[i] <= 0){
                last = i;
                break;
            }
            t -= c[i];
        }
        cout << last;
        return 0;
    }
return 0;
}
