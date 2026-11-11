#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char ch[200010];
struct N{
    long long num;
    char c;
};
vector<N> f;
vector<N> l;
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    long long mid = 0 , ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> ch[i];
        mid += a[i];
    }
    mid /= 2;
    long long mid1 = mid , cur = 1 , cur1 = n;
    while(mid)
    {
        if(mid >= a[cur]){
            f.push_back({a[cur] , ch[cur]});
            mid -= a[cur];
        }
        else
        {
            f.push_back({mid , ch[cur]});
            mid = 0;
        }
        cur++;
    }
    while(mid1)
    {
        if(mid1 >= a[cur1]){
            l.push_back({a[cur1] , ch[cur1]});
            mid1 -= a[cur1];
        }
        else
        {
            l.push_back({mid1 , ch[cur1]});
            mid1 = 0;
        }
        cur1--;
    }
    cur = 0 , cur1 = 0;
    while(cur < f.size() && cur1 < l.size()){
        if(f[cur].num < l[cur1].num){
            if(f[cur].c != l[cur1].c){
                ans += f[cur].num;
                l[cur1].num -= f[cur].num;
                cur++;
            }
            else{
                l[cur1].num -= f[cur].num;
                cur++;
            }
        }
        else if(f[cur].num == l[cur1].num){
            if(f[cur].c != l[cur1].c){
                ans += f[cur].num;
                cur1++;
                cur++;
            }
            else{
                cur1++;
                cur++;
            }
        }
        else{
            if(f[cur].c != l[cur1].c){
                ans += l[cur1].num;
                f[cur].num -= l[cur1].num;
                cur1++;
            }
            else{
                f[cur].num -= l[cur1].num;
                cur1++;
            }
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
