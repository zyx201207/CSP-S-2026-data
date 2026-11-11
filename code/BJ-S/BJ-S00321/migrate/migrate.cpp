#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,INF=0x3f3f3f3f3f3f3f3f;
int n,d,x[N],c,t;
void subtask3(){
    int q=x[2]-x[1];
    if(q>=d){
 //           cout<<q<<" "<<d<<endl;
        cout<<0<<"\n";
        return ;
    }
    cout<<max(0ll,n-2*(d/q)+1)<<endl;
}
void subtask4(){
    int a1;
    for(int i=1;i<=n;i++){
        if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
            a1=i;
            break;
        }
    }
    int a0=a1-1,l2=n;
    while(x[l2]-x[a0]>d) l2--;
    l2++;
    if(x[a1+1]-x[1]>d||x[n]-x[a1+1]>d){
        cout<<0<<"\n";
        return ;
    }
    int a2=a1+2,r1=1;
    while(x[a2]-x[r1]>d) r1++;
    r1--;
    cout<<r1*(n-l2+1)<<"\n";
}
int ans=INF,ansl=0;
void dfs(int i,int j,int step){
    if(i==j){
        if(step<ans){
            ans=step;
            ansl=0;
        }
        if(step==ans){
            ansl++;
        }
        return ;
    }
    int pos=i+1;
    while(pos<=j&&x[pos]-x[i]<=d){
        dfs(pos,j,step+1);
        pos++;
    }
}
void subtask1(){
    int fans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=INF,ansl=0;
            dfs(i,j,0);
            if(ansl==2) fans++;
        }
    }
    cout<<fans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c==11||c==12){
            subtask3();
        }
        if(c==13||c==14){
            subtask4();
        }
        if(c==0||c==1||c==2){
            subtask1();
        }
    }
    return 0;
}


