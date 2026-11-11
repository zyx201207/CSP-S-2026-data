#include<bits/stdc++.h>

using namespace std;

long long n,m,a[500050],ans[300050]={0},vis[300050]={0};
int find_last(int num,int k){
    if(vis[num]>=k&&vis[num]!=0){
        return vis[num];
    }
    for(int i=n; i>k; i--){
        if(a[i]==num){
            vis[num]=i;
            return i;
        }
    }
    return 0;
}

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%d ",&a[i]);
        vis[a[i]]=i;
    }
    for(int time=1; time<=n; time++){
        for(int i=time; i<=n; ){
            int temp=vis[a[i]];
            //cout<<"temp"<<temp<<endl;
            ans[a[i]]++;
            //cout<<"time"<<time<<"  "<<a[i]<<" ans"<<ans[a[i]]<<endl;
            if(temp==0){
                i++;
                continue;
            }
            i=temp+1;
            if(i>n){
                break;
            }
        }
    }
    for(int i=1; i<=m; i++){
        printf("%d ",a[i]);
    }

    return 0;
}
