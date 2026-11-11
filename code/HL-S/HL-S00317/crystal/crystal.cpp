#include <bits/stdc++.h>
using namespace std;
int n,ii,cnt;
long long m,a[500005],cl,cl2;
bool as=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2) cl2=a[2]-a[1];
        if(a[i]-a[i-1]!=cl2&&i>1) as=false;
    }
    if(as){
        cl=a[2]-a[1];
        while(1){
            ii++;
            m-=ii*cl;
            if(m<0) break;
            cnt++;
        }
        if((cnt+1)>n){cout<<n;return 0;}
        cout<<cnt+1;
        return 0;
    }else{
        cout<<n;
        return 0;
    }
    return 0;
}//
