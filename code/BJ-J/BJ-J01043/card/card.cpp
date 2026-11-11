#include<bits/stdc++.h>
using namespace std;
int A[500000 + 1],b[300000 + 1];
bool c[300000 + 1];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    cin >> n;
    vector<int> now_is;
    for(int i = 1;i <= n;i++){
        cin >> A[i];
        bool fla = false;
        for(int j = 0;j < now_is.size();j++){
            if(fla)
                now_is[j] = 0;
            if(now_is[j] = A[i]){
                fla = true;
            }
        }
        if(fla == false){
            now_is.push_back(A[i]);
        }
        for(int i = 0;i < now_is.size();i++){
            b[now_is[i]]++;
        }
    }
    for(int i = 1;i <= n;i++){
        if(c[A[i]] != true){
            cout << b[A[i]] << ' ';
            c[A[i]] = true;
        }
    }
    return 0;
}
/*
考试，不会写，写篇东西吧，希望能被洛谷某个大佬看见，写进奇葩大赏。
#include<bits/stdc++.h>
usint namespace std;
int main{
    cout << "AK IOI";
    return 0;
}
祝大家：
暴力出奇迹，打表过省一。
我的状态：
暴力TLE，打表MLE；
贪心是WA，dp还RE；
用树过样例，用图拉一地；
什么都不对，干脆输样例。
*/
