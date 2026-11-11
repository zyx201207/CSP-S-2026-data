#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans[500500];
long long d,x[2002000];
int min_step,min_step_time;
void check(int x1,int x2,int now_x,int step){
    if(now_x==x2){
        if(min_step>step){
            min_step=step;
            min_step_time=1;
        }
        else if(min_step==step)min_step_time++;
    }
    for(int i=now_x+1;i<=x2;i++){
        if(x[i]-x[now_x]<=d){
            check(x1,x2,i,step++);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int s=0;s<t;s++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                min_step=10000;
                min_step_time=0;
                check(i,j,i,0);
                ans[s]=min_step_time;
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
}
