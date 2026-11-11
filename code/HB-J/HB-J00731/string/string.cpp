#include<bits/stdc++.h>
using namespace std;
int n,x,head,tail,flag=-1,pre=0;
long long ans;
char k;
int a[200005][3];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>k;
        a[i][1]=x+'0';
        a[i][2]=k;
    }
    head=1;tail=n;
    while(head<tail){
        if(flag==1){
            if(a[head][2]!=a[--tail][2]) ans+=min(pre,a[tail][1]-'0');
            int u=pre;
            pre=max(pre,a[tail][1]-'0')-min(pre,a[tail][1]-'0');
            if(a[tail][1]-'0'==max(u,a[tail][1]-'0')) flag=2;
            else flag=1;
        }else if(flag==2){
            if(a[++head][2]!=a[tail][2]) ans+=min(pre,a[head][1]-'0');
            int u=pre;
            pre=max(pre,a[head][1]-'0')-min(pre,a[head][1]-'0');
            if(a[head][1]-'0'==max(u,a[head][1]-'0')) flag=1;
            else flag=2;
        }else if(flag==-1){
            if(a[head][2]!=a[tail][2]) ans+=min(a[head][1]-'0',a[tail][1]-'0');
            pre=max(a[head][1]-'0',a[tail][1]-'0')-min(a[head][1]-'0',a[tail][1]-'0');
            if(a[head][1]-'0'==min(a[head][1]-'0',a[tail][1]-'0')){
                flag=2;
            }
            else{
                flag=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
