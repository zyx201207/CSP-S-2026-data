#include<bits/stdc++.h>
using namespace std;
int a[200005][33],ans,n,m;
void q(int i){
    for(;i>=1;i--){
        int ans1=2147483647;
        bool check=0;
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j][i]==1&&a[j][31]){
                cnt++;
                ans1=ans1&a[j][0];
                //cout<<a[j][0]<<' '<<ans1<<' ';
            }
            else{
                a[j][32]=a[j][31];
                a[j][31]=0;
            }
        }
        //cout<<cnt<<'\n';
        if(cnt==m){
            ans=ans1;
            return;
        }
        else if(cnt>m){
            q(i-1);
        }
        else{
            for(int j=0;j<n;j++) a[j][31]=a[j][32];
            ans1=ans;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0,p;i<n;i++){
        cin>>p;
        a[i][0]=p;
        a[i][31]=1;
        int c=0;
        while(p>0){
            a[i][++c]=p%2;
            p/=2;
            //cout<<a[i][c];
        }
        //cout<<'\n';
    }
    q(30);
    cout<<ans;
    return 0;
}
