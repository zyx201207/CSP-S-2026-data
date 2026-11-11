#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int N,M,A[MAXN],Cnt=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int N,M;
    cin>>N>>M;
    for(int i;i<N;i++){
        cin>>A[i];
    }
    int j=0,X=0;
    sort(A,A+N);
    while(M>0){
        for(int i=0;i<=j;i++){
            X=A[i+1]-A[i];
            if(X<=M){
                M-=X;
                A[i]+=X;

            }
        }
        j++;
    }
    for(int i=1;i<N;i++){
        if(A[i]==A[0]){
            Cnt++;
        }
    }
    cout<<Cnt;
    return 0;
}
