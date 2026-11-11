#include<bits/stdc++.h>
using namespace std;
typeof long long ll;
const int N=2e5+5;
ll n,m,a[N],k=0,zd=-1,b[N][35];
void f(ll &g[]){
    while(k==n){
        k++;
        int temp=g,weishu=1;
        while(temp){
            b[weishu]=temp%2;
            temp/=2;
            weishu++;
        }
        reverse(s[k].begin(),s[k].end());
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    f(a[]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int g=0;
        }
    }
    return 0;
}
