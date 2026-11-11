#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    long long cmd1=0;
    string a;
    char c[200005];
    int b[100];
    for(int i=1;i<=n;i++){
        cin>>b[i]>>c[i];
        cmd1+=b[i];
    }
    if(cmd1>=100000000){
        cout<<cmd1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=b[i];j++){
            a+=c[i];
        }
    }

    //cout<<a<<cmd1<<'\n';
    long long cmd2=0;
    for(int i=0;i<=cmd1/2;i++){
        if(a[i]!=a[cmd1-i-1]){
            a[i]=a[cmd1-i-1];
        //cout<<i<<' '<<cmd1-i-1<<'|';
            cmd2++;
        }
    }
    cout<<cmd2;
    return 0;
}
