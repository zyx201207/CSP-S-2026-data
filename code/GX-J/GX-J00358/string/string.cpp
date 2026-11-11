#include<bits/stdc++.h>
using namespace std;
char a1[200010],a2[200010];
long long b1[200010],b2[200010],jishu=0,zong=0;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b1[i]>>a1[i];
        jishu+=b1[i];
        b2[n-i+1]=b1[i];
        a2[n-i+1]=a1[i];
    }
    for(int i=1;i<=jishu/2;i++){
        long long x,y,jx=0,jy=0;
        for(int j=1;j<=n;j++){
            jx+=b1[j];
            if(jx>=i){
                x=j;
                break;
            }
        }
        for(int j=1;j<=n;j++){
            jy+=b2[j];
            if(jy>=i){
                y=j;
                break;
            }
        }
        if(a1[x]!=a2[y]) zong++;
    }
    cout<<zong;
    return 0;
}
