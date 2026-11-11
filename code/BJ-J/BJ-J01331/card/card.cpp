#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],cnt[100010],zm[100010],gs,lc=0;
bool flag=true;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
            cin>>a[i];
    while(n--){
        lc++;
        gs=0;
        for(int i=lc;i<=n;i++){
            gs++;
            if(gs==1)
                zm[gs]=a[i];
            else{
                for(int j=1;j<gs;j++){
                    flag=true;
                    if(zm[j]==a[i]){
                        flag=false;
                        gs=j;
                        break;
                    }
                }
                if(flag){
                    zm[gs]=a[i];
                }else{
                    for(int k=gs+1;k<=100009;k++){
                        if(zm[k]==0){
                            break;
                        }else{
                            zm[k]=0;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=gs;i++)
            cnt[zm[i]]++;
        for(int i=1;i<=gs;i++)
            zm[i]=0;
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<" ";
    return 0;
}