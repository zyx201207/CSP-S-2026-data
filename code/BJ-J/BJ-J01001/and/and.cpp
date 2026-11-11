#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //测试点6
    if(m==1){
        int ma=-1;
        for(int i=1;i<=n;i++){
            ma=max(ma,a[i]);
        }
        cout<<ma<<endl;
        return 0;
    }
    //测试点13
    sort(a+1,a+1+n,greater<int>());
    cout<<a[m]<<endl;
    return 0;
}
