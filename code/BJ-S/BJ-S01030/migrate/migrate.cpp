#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans,sum;
long long d,x[2000010],mi_step;
void check(int start,int ending,int now_pos,int step){
    if(now_pos==ending){
        if(step==mi_step) sum++;
        return ;
    }
    if(step>=mi_step) return ;
    if(sum>2) return ;
    for(int i=now_pos+1;i<=ending;i++){
        if(x[i]-x[now_pos]<=d) check(start,ending,i,step+1);
        else break;
    }
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n<4){
            cout<<0;
            continue;
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                mi_step=0;
                sum=0;
                int now_pos=i;
                while(true){
                    int pos;
                    for(int k=now_pos+1;k<=j;k++){
                        if(x[k]-x[now_pos]<=d) pos=k;
                        else break;
                    }
                    mi_step++;
                    if(now_pos==pos){
                        mi_step=-1;
                        break;
                    }
                    now_pos=pos;
                    if(now_pos==j) break;
                }
                if(mi_step==-1) continue;
                check(i,j,i,0);
                if(sum==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
