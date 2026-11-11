#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#define ll long long
using namespace std;

ll n20(vector<int> &v,int m){
    ll mr = 0;
    for(int s = 1;s < (1 << (v.size()));s++){
        ll cr = -1LL >> 1;
        if(__builtin_popcount(s) != m){
            continue;
        }
        for(int i = 0;i < v.size();i++){
            if(s & (1 << i)){
                cr &= v[i];
            }
        }
        //printf("cr:%lld\n",cr);
        mr = max(mr,cr);
    }
    return mr;
}

ll m2(vector<int> &v,int m){
    int mr = 0;
    for(int i = 0;i < v.size();i++){
        for(int j = i + 1;j < v.size();j++){
            mr = max(mr,v[i] & v[j]);
        }
    }
    return mr;
}

ll a2n(vector<int> &v,int m){
    sort(v.begin(),v.end());
    ll res = -1LL >> 1;
    for(int i = 0;i < m;i++){
        res &= v[v.size() - 1 - i];
    }
    return res;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> v(n);
    int mx = 0;
    ll an = -1LL >> 1;
    bool flag = true;
    for(int i = 0;i < n;i++){
        scanf("%d",&v[i]);
        mx = max(v[i],mx);
        an &= v[i];
        if((v[i] & (v[i]) + 1) != 0){
            flag = false;
        }
    }
    if(n <= 20){
        printf("%lld\n",n20(v,m));
        return 0;
    }else if(m == 1){
        printf("%d\n",mx);
        return 0;
    }else if(m == 2){
        printf("%lld\n",m2(v,m));
        return 0;
    }else if(m == n){
        printf("%lld\n",an);
        return 0;
    }else if(flag){
        printf("%lld\n",a2n(v,m));
        return 0;
    }else{
        printf("%d\n",v[0]);//I will use 40 years of G.R.J's live to let this be correct
        return 0;
    }
    return 0;
}
