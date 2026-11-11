#include <bits/stdc++.h>
using namespace std;
const int q=100005;
long long a[q];
long long b[q];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
        b[i]+=1;
        if (b[i]==1){
            for (int j=0;j<n;j++){
                if (b[j]==1){
                    b[j]=0;
                }
            }
            b[i]=1;
        }
    }
    cout<<m<<" "<<n-m<<" "<<n-m+m;
    return 0;
}
