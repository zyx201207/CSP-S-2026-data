#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

struct Edge{
    long long z, y;
    char w;
}mp[3000000];
bool cmp(Edge x, Edge y){
    return x.z < y.z;
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    long long pos = 1;
    long long num = 0;
    for (long long i = 1; i <= n; i++){
        long long a;
        char c;
        scanf("%lld", &a);
        cin >> c;
        num += a;
        mp[i].z = pos + 1;
        pos += a;
        mp[i].y = pos;
        mp[i].w = c;
    }
    if (num % 2 == 0){
        long long last = num / 2;
        for (long long i = 1; i <= n; i++){
            if (last == mp[i].y || mp[i].z == last){
                break;
            }
            else if(last > mp[i].z && last < mp[i].y){
                n += 1;
                mp[n].z = last + 1;
                mp[n].y = mp[i].y;
                mp[n].w = mp[i].w;
                mp[i].y = last;
            }
        }
    }
    else {

        long long last = num / 2 + 1;
        for (long long i = 1; i <= n; i++){
            if (mp[i].z == last){
                mp[i].z = last + 1;
            }
            else if (last == mp[i].y){
                mp[i].y = last - 1;
            }
            else if(last > mp[i].z && last < mp[i].y){
                n += 1;
                mp[n].w = mp[i].w;
                mp[n].z = last + 1;
                mp[n].y = mp[i].y;
                mp[i].y = last - 1;
            }
        }
        n += 1;
        mp[n].z = mp[n].y = last;
        mp[n].w = mp[n - 1].w;
    }
    sort(mp + 1, mp + 1 + n, cmp);
    long long ans = 0;
    long long l = 1;
    long long r = n;
    while (l < r){
        long long l1 = mp[l].y - mp[l].z + 1;
        long long l2 = mp[r].y - mp[r].z + 1;
        if (mp[l].w != mp[r].w){
            if (l1 < l2){
                l ++;
                ans += l1;
                mp[r].y = mp[r].y - l1;
            }
            else if (l1 > l2){
                r --;
                ans += l2;
                mp[l].z = mp[l].z + l2;
            }
            else {
                l ++;
                r --;
                ans += l1;
            }
        }
        else {
            if (l1 < l2){
                l ++;
                mp[r].y = mp[r].y - l1;
            }
            else if (l1 > l2){
                r --;
                mp[l].z = mp[l].z + l2;
            }
            else {
                l ++;
                r --;
            }
        }
    }
    cout << ans;
}
