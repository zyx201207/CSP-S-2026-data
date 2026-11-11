#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define int128 __int128
#define Tianyi 712

inline void fileio(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
}

const int N=2e6+Tianyi;

int c,T;
int64 n,d;
int64 p[N];
void solveA(){
    //deng cha shu lie
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    int64 f=d/(p[2]-p[1]);
    if(f<2){
        cout<<0<<"\n";
        return;
    }
    //n*n-1
    int64 ans1=n-f-f+1;
    if(ans1<0){
        cout<<0<<"\n";
        return;
    }
    cout<<ans1<<"\n";
    return;
}
void solveB(){
    cout<<0<<"\n";
}
void baoli(){
    //bao li chu qi ji
    int ans=0;
    cout<<0<<"\n";

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fileio();
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>p[i];
        }
        //te pan
        if(c==11 || c==12){
            solveA();
        }
        if(c==13 || c==14){
            solveB();
        }
    }
    //rp++
}