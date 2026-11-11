#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=-1,maxi=-1;
long long x[200005],ans=0,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(x[i]>maxx){
                maxx=x[i];
                maxi=i;
            }
        }
        a[j]=maxx;
        x[maxi]=-1;
        maxx=-1;
        maxi=-1;
    }
    cout<<a[m];
    return 0;
}
