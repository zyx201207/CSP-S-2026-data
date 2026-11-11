#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5;
int n,m,a[N];
vector<int> d[N];
int ans[N],top,st[N],exs[N],rec[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool flag = 1;
    for(int i = 1;i<=n;i++){scanf("%d",&a[i]);if(a[i]<a[i-1])flag=0;}
    if(flag){
        for(int i = n;i>=1;i--){
            if(exs[a[i]])continue;
            ans[a[i]]=i;
            exs[a[i]]=1;
        }
    }
    else{
        int cnt = 1;
        for(int j = 1;j<=n;j++){
            if(a[j]!=a[j+1]){
                for(int k = 1;k<=m;k++){
                    ans[k]+=rec[k]*cnt;
                }
                //continue;
            }
            if(a[j]==a[j+1]){cnt++;continue;}
            for(int i = j;i<=n;i++){
                rec[i]=0;
                d[a[i]].push_back(i);
                if(exs[a[i]]){
                    while(st[top]!=a[i])exs[st[top]]=0,top--;
                    top--;d[a[i]].push_back(i);
                }
                top++;
                st[top]=a[i];
                exs[a[i]]=1;
            }   for(int k = 1;k<=m;k++){
                    rec[k]=0;
                }
            while(top>0)exs[st[top]]=0/*,ans[st[top]]++*/,rec[st[top]]=1,top--;
        }
            for(int k = 1;k<=m;k++){
                ans[k]+=rec[k]*cnt;
            }
            //continue;
    }
    for(int i = 1;i<=m;i++)printf("%d ",ans[i]);

}
//gufen:100+100+100+60
//check:bianyi,wendu
