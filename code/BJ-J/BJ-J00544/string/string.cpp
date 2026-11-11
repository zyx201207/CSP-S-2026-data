#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
char c[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 0;i < n;i++) cin>>a[i]>>c[i];
    int i = 0,k = n-1;
    long long cnt = 0,ai = 0,ak = 0;
    while(i < k){
        ai = a[i],ak = a[k];
        if(ai < ak){
            if(c[i] != c[k]) cnt += ai;
            a[k] -= ai;
            a[i] = 0;
            i++;
        }else if(ai == ak){
            if(c[i] != c[k]) cnt += ai;
            a[i] = 0;
            a[k] = 0;
            i++;
            k--;
        }else{
            if(c[i] != c[k]) cnt += ak;
            a[i] -= ak;
            a[k] = 0;
            k--;
        }
    }
    cout<<cnt;
    return 0;
}