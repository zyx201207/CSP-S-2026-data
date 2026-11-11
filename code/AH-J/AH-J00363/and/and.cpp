#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
struct F{
    int num;
    long long cnt;
}a[200005];
bool cmp(F x,F y){
    if(x.cnt!=y.cnt){
        return x.cnt>y.cnt;
    }
    return x.num>y.num;
}
bool f;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        int v=a[i].num;
        while(v!=0){
            if(v%2==1){
                a[i].cnt++;
            }
            v/=2;
        }
        if(a[i].cnt!=1){
            f=1;
        }
    }
    if(f==0){
        cout<<0;
    }
    sort(a+1,a+n+1,cmp);
    long long awy=a[1].num;
    for(int i=2;i<=m;i++){
        awy&=a[i].num;
    }
    cout<<awy;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
