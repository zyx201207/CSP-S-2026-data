#include <bits/stdc++.h>
using namespace std;
long long n,m;
map<long long,long long> c;
long long a[500005];
inline long long num(long long x){
    long long cnt = 0,p = 0;
    //printf("begin calculate %d's max crystal number\n",x);
    for(long long i = 1;i < x;i++){
        if(a[x - i] < a[x]){
            cnt += (c[a[x - i]]) * (a[x] - a[x - i]);
            p += c[a[x - i]];
            //printf("now i = %d,use:%d,crystal number = %d\n",x - i,cnt,p);
            if(cnt >= m){
                cnt -= (c[a[x - i]]) * (a[x] - a[x - i]);
                p -= c[a[x - i]];
                p += (m - cnt) / (a[x] - a[x - i]);
                cnt += (m - cnt) / (a[x] - a[x - i]) * (a[x] - a[x - i]);
                //printf("used bigger than m,correct use:%d,crystal number:%d\n",cnt,p);
                break;
            }
        }
    }
    return p + c[a[x]];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    long long v = 1;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
        c[a[i]]++;
    }
    sort(a + 1,a + n + 1);
    long long ans = -1;
    for(long long i = 1;i <= n;i++){
        ans = max(ans,num(i));
    }
    cout << ans;
    return 0;
}
/*
定义一个map，用来存储每一个数据的数量，num为求对应x可以实现的最大数量，输入后排序，接着遍历1～n，将答案取最大的值
*/
