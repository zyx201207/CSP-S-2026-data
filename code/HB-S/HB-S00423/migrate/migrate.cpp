#include<bits/stdc++.h>
#define ll long long
#define el "\n"
using namespace std;
int n,x[100005],d;
int u,v;
int c;
bool flag,vis;
int cha;
void slove(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];//1 2 3 4
    }
    sort(x+1,x+1+n);
    cha=x[2]-x[1];
    int sum=0;
    for(int i=2;i<=n;i++){
        if(x[i]-x[i-1]==cha) flag=1,vis=1,sum++;
        else{
            flag=0;
            break;
        }
    }
    if(vis==1||(d==2&&flag==1)||(sum-1)%2==0){
        if((d==2&&flag==1))cout<<n%3+n/3-1;
        else if(vis==1){
            if(n-d<3) cout<<0<<el;
            else cout<<n%3+n/3-1;
        }
        else cout<<(n-sum-1)%3+(n-sum-1)/3-1;

        return;
    }



}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T=1;
    cin>>c>>T;
    while(T--){
        slove();
    }
    return 0;
}
