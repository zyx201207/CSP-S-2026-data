#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)cin >> a[i];
    sort(a+1, a+n+1);
    long long l=a[1], r=a[n];
    long long ans=-1;
    for(int tp = n; tp>=1; tp--){
        long long mid = a[tp];
        int temp = m;
        int sum=0;
        for(int i=tp; i>=1; i--){
            if(a[i]>mid)continue;
            else{
                long long dif = mid-a[i];
                if(dif<=temp){
                    sum++;
                    temp-=dif;
                }
                else break;
            }
        }
        if(sum>=ans){
            ans = sum;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
