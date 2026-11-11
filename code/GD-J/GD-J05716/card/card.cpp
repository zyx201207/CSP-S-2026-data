#include<bits/stdc++.h>
using namespace std;
long long F[300010],ans[300010];
long long n,m,A[500010];
vector <int> K;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=1;i<=m;i++){
        F[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(F[A[j]]!=-1){
                while(K.size()!=F[A[j]]+1){
                    F[K[K.size()-1]]=-1;
                    K.pop_back();
                }
            }else{
                K.push_back(A[j]);
                F[A[j]]=K.size()-1;
            }
        }
        for(int i=1;i<=m;i++){
            if(F[i]!=-1){
                ans[i]++;
                F[i]=-1;
            }
        }
        while(!K.empty()){
            K.pop_back();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
