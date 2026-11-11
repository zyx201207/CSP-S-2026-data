#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long m, n, a[500001], ans=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    long long c, s;
    for(int i=n;i>0;i--){
        c=m, s=1;
        for(int j=i-1;j>0;j--){
            long long x=a[j];
            if(a[i]==x){
                s++;
                continue;
            }
            while(c>0&&a[i]>x){
                c--;
                x++;
                if(a[i]==x){
                    s++;
                    break;
                }
            }
            if(c<=0){
                break;
            }
        }
        ans=max(ans, s);
    }
    cout << ans;
    return 0;
}
