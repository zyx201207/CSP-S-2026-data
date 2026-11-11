#include<iostream>
#include<string>
using namespace std;
int a[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)
            if(a[i]&a[j]>cnt)cnt=a[i]&a[j];
    }
    cout<<cnt;
    return 0;
}
