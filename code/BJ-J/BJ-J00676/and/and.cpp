#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long q[200020];
    bool f=1,ff=1;
    for(int i=1;i<=n;i++){
        cin>>q[i];
        if(q[i]!=i-1){
            f=0
        }else if(!(q[i]<4)){
            ff=0
        }
    }
    if(f){
        int ww=1
        sort(q+1,q+n+1);
        while(ww*2<=q[n-m+1]){
            ww*=2;
        }
        cout<<ww;
    }else if(m==1){
        sort(q+1,q+n+1);
        cout<<q[n];
    }else if(ff){
        sort(q+1,q+n+1);
        bool s1=0,s2=0,s3=0;
        for(int i=n;i>=n-m+1;i--){
            if(q[i]==1){
                s1=1;
            }else if(q[i]==2){
                s2=1;
            }else{
                s3=1;
            }
        }
        if((s1&&(!s2)&&s3)||(s1&&(!s2)&&(!s3))){
            cout<<1;
        }else if(((!s1)&&s2&&s3)||(s2&&(!s3)&&(!s1))){
            cout<<2;
        }else if(s3&&(!s2)&&(!s1)){
            cout<<3;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    return 0;
}
