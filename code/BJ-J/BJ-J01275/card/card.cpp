#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int f=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            f=0;
        }
    }
    if(f==1){
        for(int i=1;i<=m;i++){
            cout<<n<<" ";
        }
    }
    else if(m==1){
        cout<<n;
    }else if(m==2){
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
                int f1=0,f2=0;
            for(int j=i;j<=n;j++){
                if(a[j]==1)f1=1;
                if(a[j]==2)f2=1;
                if(f1==1&&f2==1){
                    break;
                }
            }
            if(f1==1)ans1++;
            if(f2==1)ans2++;
        }
        cout<<ans1<<" "<<ans2;
    }
    return 0;
}
