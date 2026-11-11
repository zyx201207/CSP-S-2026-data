#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,ans=-2,sum=-1,sum1[maxn];
long long a[maxn];
bool flag[maxn];
void dfs(int d){
//    cout<<"d="<<d<<endl;
    if(sum<=ans)return;
    if(d==m){
        ans=sum;
//        cout<<"newans="<<ans<<endl;
        return;
    }
//    cout<<"indfs"<<endl;
    for(int i=1;i<=n;i++){
        if(flag[i]){
            flag[i]=false;
            sum1[d]=sum;
            if(sum=-1)sum=a[i];
            else sum=sum^a[i];
//            cout<<a[i]<<" change->sum1["<<d<<"]="<<sum1[d]<<",sum="<<sum<<endl;
            dfs(d+1);
            flag[i]=true;
            sum=sum1[d];
//            cout<<sum<<"is back\n";
            sum1[d]=0;
        }
    }
    return;
}
int main(){
    memset(flag,true,sizeof(flag));
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
//    for(int i=1;i<=n;i++)cout<<a[i]<<",";
//    cout<<endl;
    sum=a[1];
    if(m==1){
        cout<<sum;
    }else{
        dfs(0);
        cout<<ans;
    }
    return 0;
}

