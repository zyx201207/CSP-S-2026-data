#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    double sum;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    int max=0;
    double w=abs(a[1]-sum);
    for(int i=2;i<=n;i++){
        if(abs(a[i]-sum)<=w){
            w=abs(a[i]-sum);
            max=a[i];
        }
    }
    cout<<max;
    return 0;
}
