#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int C,T,N,D,A[MAXN],Ans,Cnt,X;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>N>>D;
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            if(A[i]+d>=A[i+1]) Ans++;
            for(int j=0;j<N;j++){
                if(A[i]+d>=A[i+2]) Cnt++;
            }
            if(Ans==Cnt){
                Ans=0;
                Cnt=0;
                X++;
            }
        }
        cout<<X<<endl;
    }
    return 0;
}

