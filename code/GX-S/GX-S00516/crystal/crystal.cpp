#include<bits/stdc++.h>
using namespace std;
int n,ins,l,M;long long m,crystals[500500];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    M=-1;
    l=0;
    ins=1;
    for(int i=0;i<n;i++){
        cin>>crystals[i];
    }
    sort(crystals,crystals+n);
    while(m>=0){
        int need = (crystals[ins]-crystals[ins-1])*(ins-l);
        if(need>m){
            while(need>m && l!=ins){
                m+=crystals[ins-1]-crystals[l];
                need-=crystals[ins]-crystals[ins-1];
                l++;
                M=max(M,ins-l+1);
            }
        }
        M=max(M,ins-l+1);
        if(ins==n-1)break;
        m-=need;
        ins++;
    }
    cout<<M;
    return 0;
}
