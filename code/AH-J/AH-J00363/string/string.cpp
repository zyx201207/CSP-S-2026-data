#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct F{
    int m;
    char c;
}a[200005];
int n;
long long cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].m>>a[i].c;
    }
    long long u=a[1].m,v=a[n].m;
    int l=1,r=n;
    while(l<=r){
        if(a[l].c!=a[r].c){
            cnt+=min(u,v);
        }
        if(u<v){
            v-=u;
            l++;
            u=a[l].m;
        }else if(v<u){
            u-=v;
            r--;
            v=a[r].m;
        }else{
            l++;
            r--;
            u=a[l].m;
            v=a[r].m;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
