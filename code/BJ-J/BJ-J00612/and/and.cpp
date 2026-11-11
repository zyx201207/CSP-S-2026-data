#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[200005][35];
bool b[200005];
bool ans[35];
void er(long long x,int i,int l){
    if(l==0){
        return;
    }
    a[i][l]=x%2;
    er(x/2,i,l-1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long a1;
        cin>>a1;
        er(a1,i,20);
        b[i]=1;
    }
    for(int i=1;i<=20;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==1&&b[j]==1){
                cnt++;
            }
        }
        if(cnt>=m){
            ans[i]=1;
            for(int j=1;j<=n;j++){
                if(a[j][i]==0){
                    b[j]=0;
                }
            }
        }else{
            ans[i]=0;
        }
    }
    long long ansz=0;
    for(int i=1;i<=20;i++){
        if(ans[i]==1){
            ansz+=pow(2,20-i);
        }
    }
    cout<<ansz;
    return 0;
}
