#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("string1.in", "r", stdin);
    //freopen("string1.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    string a;
    int cishu = 0;
    char b;
    int m = 0;
    for(int i=0; i<n; i++){
        int i_a;
        cin >> i_a;
        char c;
        cin >> c;
        if(i_a>m){
            m = i_a;
            b = c;
        }
        for(int j=0; j<i_a; j++){
            s += c;
            a += c;
        }
    }
    int sum = s.size();
    int num = a.size();
    for(int i=0; i<sum; i++){
        if(s[i]!=s[sum-1]){
            cishu ++;
        }
   }

    for(int i=1; i<sum-1; i++){
        if(s[i]!=b){
            cishu ++;
       }
    }

    cout << cishu;
    return 0;
}
