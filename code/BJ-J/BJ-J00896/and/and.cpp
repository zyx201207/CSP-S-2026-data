#include<bits/stdc++.h>
using namespace std;
int n,m,a[20009],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ans=a[n-1];
    for(int i=n-1;i>=0;i++){
        for(int j=1;j<=m;j++){
            ans=ans&&a[i];
        }
    }
    //在光绪二十六年
    //神助拳义和团
    //扶清灭洋
    //五十五天在北京
    //......
    //来自中原一群伙伴
    //结庐东南山
    
    cout<<ans;
    return 0;
}
