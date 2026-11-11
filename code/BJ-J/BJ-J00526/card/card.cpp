#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N],ans[M];
bool is_use[M];
int temp[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1,j=n;i<=n;i++){
        if(a[i]==a[j])ans[a[i]]++;
        else {
            ans[a[i]]++;
            ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
