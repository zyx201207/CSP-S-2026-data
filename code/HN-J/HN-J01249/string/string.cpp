#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);

    vector<pair<long , char>>arr;
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0 ; i < n ; i++){
        long a;char b;
        cin >> a >> b;
        arr[i] = {a , b};
    }
    int L = 0;
    int R = n-1;
    int LL = arr[L].first;
    int RR = arr[R].first;
    long long sum = 0;
    //左边和右边比较：如果左右数量不一样且字符不一样，较少方完全抵消并进入下一轮，较多方部分抵消
    while (L<R){

        if (LL > RR){
            if (arr[L].second != arr[R].second)sum += RR;
            LL -= RR;
            R--;
            RR = arr[R].first;  //两边剩余为比较字符数量大于0，留着下一轮抵消，否则换下一轮字符
        }
        else if (LL < RR){
            if (arr[L].second != arr[R].second)sum += LL;
            RR -= LL;
            L++;
            LL = arr[L].first;
        }
        else{
            if (arr[L].second != arr[R].second)sum += LL;
            L++;
            R--;
            LL = arr[L].first;
            RR = arr[R].first;
        }

    }

    cout << sum;

    return 0;
}
//O(n+1/2n);
