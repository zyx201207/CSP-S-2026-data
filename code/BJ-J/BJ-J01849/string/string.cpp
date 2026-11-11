#include<bits/stdc++.h>
using namespace std;
long long a[222222];
char c[222222],s[1111111111];
int n;
long long sum=0,cum=0;
char csp(int x){
     int y=0;
     for(int i=1;i<=n;i++){
        if(y<=x && y+a[i]>=x){
            return c[i];
        }
        y+=a[i];
     }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    for(int i=1;i<=sum*0.5;i++){
        if(csp(i)!=csp(sum+1-i)){
            cum++;
        }
    }
    cout<<cum;
    return 0;
}
