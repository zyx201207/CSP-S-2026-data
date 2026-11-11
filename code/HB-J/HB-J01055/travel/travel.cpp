#include<bits/stdc++.h>
using namespace std;
int n,m,g=0,x,y;
char a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>x>>a>>m>>y>>b;
    if(n==m){
        g+=1000;
        if(x==y){
            g+=100;
            if(int(a)<=67&&int(b)<=67||int(a)>67&&int(b)>67){
                g+=10;
                if(int(a)+1==int(b)||int(a)-1==int(b))g+=1;
            }
        }
        cout<<g;
        return 0;
    }
    cout<<"0000";
}
