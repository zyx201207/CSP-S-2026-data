#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.out","w",stdout);
    freopen("and3.in","r",stdin);
    int n,m;
    map<int,int>v[35],siz;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=0;j<31;j++){
            if(a/(1<<j)%2==1){
                v[j][a]++;
                siz[j]++;
            }
        }
    }
    int ans=0;
    for(int i=31;i>=0;i--){
        if(siz[i]>=m){
            for(int j=i;j>=0;j--){
                ans+=pow(2,j);
                for(auto x:v[i]){
                    if(v[j][x.first]==0){
                        ans-=pow(2,j);
                        break;
                    }
                }
            }
            break;
        }
    }
    cout<<ans;
}
