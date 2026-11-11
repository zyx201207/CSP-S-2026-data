#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
bool cmp(int a,int b){
    return a>b;
}
int sum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    sum=a[1];
    cout<<a[1]<<" "<<sum<<endl;
    for(int i=2;i<=m;i++){
        sum=sum&a[i];
        cout<<a[i ]<<" "<<sum<<endl;
    }
    cout<<sum;
    return 0;
}
