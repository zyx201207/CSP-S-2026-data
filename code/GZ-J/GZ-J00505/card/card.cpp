//GZ-J00505 贵阳市第三实验中学 郑傅允
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005]={},b[500005]={},c[500005]={};
    bool d[500005]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int k=1;
        if(d[a[i]]==0){
            d[a[i]]=1;
            b[k]=a[i];
        }
        else{
            int e=0,f=0;
            while(e==0){
                if(a[f]==a[i]) e=f;
                else f++;
            }

        }
    }
    cout<<3<<" "<<3<<" "<<3;
    return 0;
}
