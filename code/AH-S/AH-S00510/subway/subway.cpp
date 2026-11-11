#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int C,N,M,D,Q,Min=0x3f3f3f3f,S,E;
int W[MAXN],K[MAXN];
struct Node{
    int A,T;
}Nod[MAXN];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>N>>M>>D>>Q;
    for(int i=1;i<=M;i++){
        cin>>W[i];
    }
    for(int i=1;i<=N;i++){
        cin>>K[i];
        for(int j;j<=K[i];j++){
            cin>>Nod[i].A>>Nod[i].T;
        }
    }
    while(Q--){
        cin>>S>>E;
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                Min=min(W[i]+Nod[i].T+Min,Min);
            }
        }
        cout<<Min<<endl;
    }
    return 0;
}
