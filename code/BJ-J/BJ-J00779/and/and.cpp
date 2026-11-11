#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],b[N],c[N];
int ans;
int max_=INT_MIN;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        max_=max(max_,a[i]);
    }
    int tmp=pow(2,30);
    for(int i=30;i>=0;i--){
        if(tmp>max_){
            tmp=tmp/2;
            continue;
        }
        int p=0;
        for(int j=1;j<=n;j++){
            b[j]=(a[j]/tmp)%2;
            if(b[j]){
                p++;
                c[p]=a[j];
            }
        }
        //cout<<p<<" "<<tmp<<endl;
        if(p<m){
            tmp=tmp/2;
            continue;
        }
        ans+=tmp;
        for(int j=1;j<=p;j++){
            a[j]=c[j];
        }
        n=p;
        tmp=tmp/2;
    }
    cout<<ans<<endl;
    return 0;
}
