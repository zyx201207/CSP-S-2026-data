#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 100;
struct node{
    long long len,s,e;
    char c;
}a[N];
long long sum[N][30];
long long ans,res,n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
        a[i].s = ans + 1;
        ans += a[i].len;
        a[i].e = ans;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=26;j++){
            char s = char(j + 96);
            if(s != a[i].c){
                sum[i][j] = sum[i - 1][j];
            }else{
                sum[i][j] = sum[i - 1][j] + a[i].len;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        // ans + i - 1
        long long R = ans - a[i].s + 1,L = ans - a[i].e + 1;
        long long l = 1,r = n,pos1 = -1;
        while(l <= r){
            long long mid = (l + r) >> 1;
            if(a[mid].e >= L){
                pos1 = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        long long pos2 = -1;
        l = 1,r = n;
        while(l <= r){
            long long mid = (l + r) >> 1;
            if(a[mid].e >= R){
                pos2 = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        int y = (int)a[i].c - 96;
        long long x = sum[pos2][y] - sum[pos1 - 1][y];
        //  - (a[pos2].e - R) - a[pos1 - 1].e + L)
        if(a[pos2].c == a[i].c) x -= (a[pos2].e - R);
        if(a[pos1].c == a[i].c) x -= (L - a[pos1].s);
        long long z = R - L + 1 - x;
        res += z;
    }
    cout<<res / 2;
    return 0;
}