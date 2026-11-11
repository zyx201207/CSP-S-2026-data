#include<bits/stdc++.h>
using namespace std;
long long a[600000],b[600000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,ans=0;
    long long m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];

    }
    for(int i=1;i<=n;i++){
        long long n1=m;
        int ge=1;
        for(int j=i;j<=n;j++){
            if((a[j+1]-a[j])*(j-i+1)<=n1){
                n1=n1-((a[j+1]-a[j])*(j-i));
                ge++;
            }
            else {ans=max(ans,ge);
                break;}
        }
    }
    cout << ans;


}
