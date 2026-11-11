#include<bits/stdc++.h>
using namespace std;
    int n[2500001];
    char zf[20005];
    //char zf[1000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,max=0,nax=0,q=0;
    cin>>a>>b;
    for(int j=1;j<=b-1;j++){
            for(int i=1;i<=a;i++){
            cin>>n[i];
            if(n[i]>=max){
                max=n[i];
                q=i;
            }
        }
        n[q]=1;
    }
    for(int i=1;i<=a;i++){
        cin>>n[i];
        if(n[i]>=nax){
            nax=n[i];
        }
    }

    cout<<nax;
    return 0;
}
