#include<iostream>
using namespace std;

const int MAXN=5e5+5,MAXM=3e5+5;
int n,m,a[MAXN],ans[MAXN];
int top,st[MAXN];
bool flag[MAXM];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    bool f=true;
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1]){
            f=false;
            break;
        }
    if(f){
        for(int i=1;i<=n;i++)cout<<i<<' ';
        cout<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            top=0;
            for(int i=1;i<=m;i++)flag[i]=false;
            for(int j=i;j<=n;j++){
                if(flag[a[j]])
                    while(a[st[top]]!=a[j])flag[a[st[top--]]]=false;
                else st[++top]=j,flag[a[j]]=true;
            }
            for(int i=1;i<=m;i++)ans[i]+=flag[i];
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}