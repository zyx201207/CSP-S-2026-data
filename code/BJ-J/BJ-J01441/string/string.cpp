#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

ll tnsp(vector<int> &a,vector<char> &c){
    string s;
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a[i];j++){
            s += c[i];
        }
    }
    ll res = 0;
    for(int i = 0;i < s.length() / 2;i++){
        if(s[i] != s[s.length() - 1 - i]){
            res++;
        }
    }
    return res;
}

ll trs(vector<int> &a,vector<char> &c,ll sa){
    int lp = 0;
    int rp = a.size() - 1;
    int lc = 0,rc = 0;
    ll res = 0;
    while(lp < rp){
        if(c[lp] != c[rp]){
            res++;
        }
        lc++;
        rc++;
        if(lc >= a[lp]){
            lp++;
            lc = 0;
        }
        if(rc >= a[rp]){
            rp--;
            rc = 0;
        }
    }
    return res;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    vector<char> c(n);
    int mx = 0;
    ll sa = 0;
    for(int i = 0;i < n;i++){
        scanf("%d %c",&a[i],&c[i]);
        mx = max(a[i],mx);
        sa += a[i];
    }
    if(1LL * n * mx <= 10000000LL){
        printf("%lld\n",tnsp(a,c));
        return 0;
    }else{
        printf("%lld\n",trs(a,c,sa));
        return 0;
    }
    //printf("%lld\n",trs(a,c,sa));
    return 0;
}
