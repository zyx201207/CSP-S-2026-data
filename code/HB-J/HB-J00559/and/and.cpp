#include<bits/stdc++.h>
using namespace std;
int ans;
int a[200005];
void S(int k,int j,int r){
    if(j==0){
        for(int i=0;i<r;i++){
            ans=a[i];
            S(k,j+1,r);
        }
    }else{
        for(int i=0;i<r;i++){
            if(j<k){
                    ans=max(ans,ans&a[i]);
                    S(k,j+1,r);
            }
            else {
                cout << ans;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    S(m,0,n);
    return 0;
}
