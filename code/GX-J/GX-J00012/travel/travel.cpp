#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r","std.in");
    freopen("travel.out","w","std.out");
    int n,a,c,x;
    cin>>n>>a>>c>>x;
    int d[8]{'A','B','C','D','F'};
    n=c;
    if(n!=16&&n!=1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a+d[0]&&x+d[1]||x+d[0]&&a+d[1]||x+d[1]&&a+d[2]||a+d[1]&&x+d[2]||a+d[3]&&x+d[4]||a+d[4]&&x+d[3]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c==n&&n!=16&&n!=1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(a==x&&a+d[0]&&x+d[1]||x+d[0]&&a+d[1]||x+d[1]&&a+d[2]||a+d[1]&&x+d[2]||a+d[3]&&x+d[4]||a+d[4]&&x+d[3]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
