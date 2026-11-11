#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int a[500005];
    long long n,m,cnt=INT_MIN,tmp=0,tmp_cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
                if(tmp+(a[i]-a[j])<=m){
                    tmp=tmp+(a[i]-a[j]);
                    tmp_cnt++;
                }
        }
        if(tmp_cnt>cnt){
            cnt=tmp_cnt;
        }
        tmp=0;
        tmp_cnt=0;
    }
    cout<<cnt;
    return 0;
}