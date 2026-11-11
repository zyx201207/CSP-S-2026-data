#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],cnt,sum;
int cmp(int x,int y){
    return x>y;
}
void dfs(int k){
    long long s=m;
    for(int i=k+1;i<=n;i++){
        if(a[i]!=a[k]&&s==0){
            break;
        }
        if(a[i]!=a[k]){
            long long h=a[i];
            if(s>=abs(a[k]-h)){
                s-=abs(a[k]-h);
                sum++;
            }else{
                break;
            }
        }
        if(a[i]==a[k]){
            sum++;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(cnt>=n-i+1){
            break;
        }
        sum=1;
        dfs(i);
        cnt=max(cnt,sum);
    }
    cout<<cnt;
    return 0;
}
