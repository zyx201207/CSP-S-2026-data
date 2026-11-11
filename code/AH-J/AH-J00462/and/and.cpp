#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
    }else if(m==2){
        sort(a,a+n);
        for(int i=n-1;i>=0;i--){
            if(a[i]==a[i-1]){
                cout<<a[i];
                break;
            }
        }
    }
    return 0;
}
