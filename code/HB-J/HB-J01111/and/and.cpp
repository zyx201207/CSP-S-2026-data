#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+7;
int n,m,a[N],help[N],mx,MX,ad=1<<30;
void f(int index,int last,int sum){
    if(index>m){
        mx=max(sum,mx);
        return;
    }
    for(int i=last+1;i<=n;i++){
        f(index+1,i,sum&a[i]);
    }
}
bool cmp(int a,int b){return a>b;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==n){
        int ad=a[1];
        for(int i=2;i<=n;i++)ad&=a[i];
        cout<<ad;
        return 0;
    }
    if(2000<n&&n<=2e5){
        sort(a+1,a+1+n,cmp);
        cout<<a[m];
        return 0;
    }
    for(int i=1;i<=n;i++)f(2,i,a[i]);
    cout<<mx;
    return 0;
}
