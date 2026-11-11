#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[200005],maxn,minn=0x3f3f3f3f,cnt1,cnt2,cnt3;
long long f=1,ans=-0x3f3f3f3f,s;
bool flag;
void dfs(int x,long long sum,int cnt){
    if(cnt>=m){
        ans=max(ans,sum);
        return ;
    }
    if(x>n) return ;
    if(sum<ans) return ;
    dfs(x+1,sum&a[x],cnt+1);
    dfs(x+1,sum,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    s=(s<<31)-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>4) flag=1;
        minn=min(minn,a[i]);
        maxn=max(maxn,a[i]);
        s&=a[i];
    }
    if(n<=20){
        dfs(1,(f<<31)-1,0);
        cout<<ans;
    }else if(n<=2000){
        if(m==1){
            cout<<maxn;
        }else if(m==2){
            maxn=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    maxn=max(maxn,a[i]&a[j]);
                }
            }
        }else{
            cout<<s;
        }
    }else if(!flag){
        for(int i=1;i<=n;i++){
            if(a[i]==1) cnt1++;
            else if(a[i]==2) cnt2++;
            else if(a[i]==3) cnt3++;
        }
        if(cnt3>=m){
            cout<<3;
        }else if(cnt2+cnt3>=m){
            cout<<2;
        }else if(cnt1+cnt3>=m){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<minn;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
