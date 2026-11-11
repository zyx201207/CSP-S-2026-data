#include <bits/stdc++.h>
using namespace std;
struct node{
    long long f;
    char c;
};
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n , ans = 0;
    cin >> n;
    vector<node> a(n + 1);
    long long sum = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i].f >> a[i].c;
        sum += a[i].f;
    }
    //vector<node> d(n + 1);
    //for(int i = 2;i <= n;i ++){
    //    if(a[i].c == a[i - 1].c){
    //        a[i].f += a[i - 1].f;
    //    }else{
    //        d.push_back(a[i - 1]);
    //    }
    //}
    //for(int i = 0;i < d.size();i ++){
    //    for(int j = d.size() - 1;j > i;j --){
    //        if(i > j) break;
    //        int ab = min(d[i].f , d[j].f);
    //        if(d[i].f > ab){
    //            int cnt = 0;
    //            while(ab <= 0){
    //                ab -= d[i].f;
    //                if(d[i].c != d[j].c) ans += d[i].f;
    //                i ++;
    //            }
    //            cnt = d[i].f + ab;
    //            d[i].f -= cnt;
    //        }
    //        if(d[j].f > ab){
    //            int cnt = 0;
    //            while(ab <= 0){
    //                ab -= d[j].f;
    //                if(d[i].c != d[j].c) ans += d[j].f;
    //                j --;
    //            }
    //            cnt = d[j].f + ab;
    //            d[j].f -= cnt;
    //        }
    //    }
    //}
    cout << sum / 2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
