//贾启航 GZ-J00385 个人报名
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m=0;
    cin>>n;
    string a;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        char y;
        cin >>y;
        for(int j=1;j<=x;j++){
            a+=y;
        }
    }
    for(int i=0;i<=a,size()/2;i++){
        if(a(i)!=a(a.size()/2-i)){
           m++;
        }
    }
    cout<<m;
    return 0;
}
