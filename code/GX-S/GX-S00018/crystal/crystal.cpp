#include<bits/stdc++.h>
using namespace std;
#define maxn 500050
long long s[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m;
    int n;
    cin>>n>>m;
    for(int o=0;o<n;++o){
        cin>>s[o];
    }
    sort(s,s+n);
    long long he;
    int h=0,h0=-999;
    for(int o=0;o<n;++o){
        long long num=0;
        for(int p=o;p>=0;p--){
            num+=s[o]-s[p];

        }
        if(num<=m){
            ++h;
            if(h>h0){
                h0=h;
            }
        }
        else{continue;}
    }
    cout<<h0<<"\n";
    return 0;
}
