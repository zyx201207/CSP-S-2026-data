#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m;
int a[N];
int ans[M];
int main(){
    ios::sync_with_stdio(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>a[1];
    ans[1]=1;
    int k=1;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1]) k++;
        else {
            cout<<k<<' ';
            k++;
        }
    }
    return 0;
}
