#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxn;
int a[N];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=(i+1);j<=n;j++){
                int c=a[i]&a[j];
                maxn=max(c,maxn);
            }
        }
        cout<<maxn;
    }


    return 0;
}
