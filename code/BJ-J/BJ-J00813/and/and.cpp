#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
bool flag=true;
int sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1) sum=a[i];
        else sum=sum&a[i];
        ans=max(ans,a[i]);
    }
    if(m==1){
        cout<<ans;
        flag=false;
    }
    else if(m==2&&flag){
        int cnt=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                cnt=max(cnt,(a[i]&a[j]));
        cout<<cnt;
        flag=false;
    }
    else if(m==n-1&&flag){
        int tmp=0;
        for(int i=1;i<=n;i++){
            int t=-100;
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                if(t==-100) t=a[j];
                else t=t&a[j];
            }
            tmp=max(tmp,t);
        }
        cout<<tmp;
        flag=false;
    }
    else if(m==n&&flag) cout<<sum;
    return 0;
}
