#include<bits/stdc++.h>
using namespace std;
int n,m;
long long x1,x2,bei=1;
bool wz[200009][32],cz[200009],ans[32];
void ly(int x,int d){
    int dq=31;
    while(x>0){
        if(x%2==0){
            wz[d][dq]=false;
        }else{
            wz[d][dq]=true;
        }
        x/=2;
        dq--;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int a=1;a<=n;a++){
        cin>>x1;
        ly(x1,a);
        cz[a]=true;
    }
    for(int a=0;a<32;a++){
        int t=0;
        for(int b=1;b<=n;b++){
            if(wz[b][a]&&cz[b]){
                t++;
            }
        }
        if(t>=m){
            ans[a]=true;
            for(int b=1;b<=n;b++){
                if(!wz[b][a]){
                    cz[b]=false;
                }
            }
        }
    }
    for(int a=31;a>=0;a--){
        if(ans[a]){
            x2+=bei;
        }
        bei*=2;
    }
    cout<<x2;
    return 0;
}