#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],stk[500001],lasti[300001],flag[300001],ans[300001],top;
struct node{
    int first,second;
}b[500001];
bool check1(){
    for(int i=1;i<n;i++)if(a[i]>a[i+1])return 0;
    return 1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n<=500){
        for(int i=1;i<=n;i++){
            memset(flag,0,sizeof(flag));
            top=0;
            for(int j=i;j<=n;j++){
                int k;
                for(k=top;k>=1;k--)if(stk[k]==a[j]){
                    top=k-1;
                    break;
                }
                stk[++top]=a[j];
            }
            for(int j=1;j<=top;j++)if(flag[stk[j]]==0)flag[stk[j]]=1,ans[stk[j]]++;
        }
    }
    else if(check1()){
        for(int i=1;i<=n;i++){
            memset(flag,0,sizeof(flag));
            memset(lasti,0,sizeof(flag));
            top=0;
            for(int j=i;j<=n;j++){
                if(lasti[a[j]]!=0)top=lasti[a[j]];
                stk[++top]=a[j];
                lasti[a[j]]=top;
            }
            for(int j=1;j<=top;j++)if(flag[stk[j]]==0)flag[stk[j]]=1,ans[stk[j]]++;
        }
    }else if(m<=2){
        for(int i=1;i<n;i++)if(a[i]==a[i+1])a[i]=0;
        for(int i=1;i<=n;i++)if(a[i]!=0)b[++top]={a[i],i};
        int st=1;
        for(int i=1;st<=top&&i<=n;i++){
            while(b[st].second<i)st++;
            if((top-st)<=1)for(int j=st;j<=top;j++)ans[b[j].first]++;
            if(b[1].first==1&&(top-st)>2&&(top-st)%2==0)ans[1]++;
            if(b[1].first==2&&(top-st)>2&&(top-st)%2==0)ans[2]++;
            if((top-st)>1&&(top-st)%2==1)ans[1]++,ans[2]++;
        }
    }
    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}