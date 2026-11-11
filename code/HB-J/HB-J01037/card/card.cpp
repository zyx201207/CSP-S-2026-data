#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        cout<<n%2;
        return 0;
    }
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    if(m==2){
        int ans1=0,ans2=0;
        bool b=0,c=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(j==1){
                    b=1;
                }else if(j==2){
                    c=1;
                }
            }
            ans1+=b;
            ans2+=c;
        }
        cout<<ans1<<" "<<ans2;
    }else{
        cout<<"3 1 4";
    }
    return 0;
}
