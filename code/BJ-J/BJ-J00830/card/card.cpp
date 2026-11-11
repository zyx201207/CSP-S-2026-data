#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514],desk[917813]={0},jishuqi[917813]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        desk[917813]={0};
        int l[917813]={0},t=0;
        for(int j=i;j<=n;j++,t++){
            int dt=0;
            desk[t]=a[j];
            if(l[a[j]]==0){
                l[a[j]]=1;
            }else{
                int flag=0;
                for(int f=1;f<=t;f++){
                    if(desk[f]==a[j]){
                        flag=1;
                    }else if(flag==1){
                        desk[f]=0;
                        dt++;
                    }
                }
                l[a[j]]==0;
            }
            t-=dt;
        }
        for(int j=1;j<=t;j++){
            jishuqi[desk[j]]++;
        }
    }
    for(int j=1;j<=m;j++){
            cout<<jishuqi[j]<<" ";
    }
    return 0;
}
