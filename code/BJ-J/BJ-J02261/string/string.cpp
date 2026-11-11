#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N];
string c[N];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,p=n,x=0;
    while(i<p){
        if(c[i]!=c[p]){
            x=1;
        }
        else{
            x=0;
        }
        if(a[i]>a[p]){
            ans+=a[p]*x;
            a[i]-=a[p];
            p--;
        }
        else if(a[i]==a[p]){
            ans+=a[i]*x;
            i++;
            p--;
        }
        else{
            ans+=a[i]*x;
            a[p]-=a[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
