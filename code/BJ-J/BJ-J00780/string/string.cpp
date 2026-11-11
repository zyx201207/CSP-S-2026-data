#include <bits/stdc++.h>
using namespace std;
int n,a,x=1;
char m;
char b[2000500];
int main(){
    freopen("string.in","r".stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>m;
        for(int j=1;j<=a;j++){
            b[x]=m;
            x++;
        }
    }
    int r=n,l=1,cnt=0;
    while(l>r){
        if(b[l]!=b[r]){
            cnt++;
        }
        r--;
        l++;
    }
    cout<<cnt;
    return 0;
}