#include<iostream>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,h;
    long long a[200005];
    long long b[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>h;
        a[i]=h;
    }
    int cnt=0;
    for(int i=1;i<n;i++){
        cnt=a[i]&a[i-1];
    }
    cout<<cnt;
    return 0;
}
