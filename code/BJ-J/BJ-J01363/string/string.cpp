#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
char a[1000000000];
int main(){
    char SFM01;
    freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);
    int n,x,bgind=1,lsind=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>SFM01;
        for(int j=0;j<x;j++){
            a[bgind]=SFM01;
            bgind++;
        }
    }
    bgind--;
    int cnt=0;
    while(lsind<=bgind){
        if(a[lsind]!=a[bgind]) cnt++;
        lsind++;
        bgind--;
    }
    cout<<cnt;
    return 0;
}
