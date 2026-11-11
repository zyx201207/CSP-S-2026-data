#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[222222];
char ch[222222];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    int indl = 1;
    int indr = n;
    ll ans = 0;
    while(indl<indr){
        if (a[indl]>a[indr]){
            a[indl]-=a[indr];
            if (ch[indl]!=ch[indr]){
                ans+=a[indr];
            }
            indr--;
        }else if (a[indl]<a[indr]){
            a[indr]-=a[indl];
            if (ch[indl]!=ch[indr]){
                ans+=a[indl];
            }
            indl++;
        }else{
            if (ch[indl]!=ch[indr]){
                ans+=a[indl];
            }
            indl++;
            indr--;
        }
    }
    cout<<ans;
    return 0;
}
