#include <bits/stdc++.h>
using namespace std;

int n,m;
const int N=5e5+7;
const int M=3e5+7;
int a[N];
int first[M];
int last[M];
int cnt[M];
int stk[3007];
int top=0;

bool ord(){
    for(int i=1;i<n;i++)if(a[i]>a[i+1])return false;
    return true;
}

int exist(int x){
    for(int k=1;k<=top;k++)if(stk[k]==x)return k;
    return 0;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        first[a[i]]=min(first[a[i]],i);
        last[a[i]]=max(last[a[i]],i);
    }
    if(ord()){
        for(int k=1;k<=m;k++)cout<<last[k]<<" ";
        cout<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            top=0;
            for(int j=i;j<=n;j++){
                int ok=exist(a[j]);
                if(ok)top=ok;
                else stk[++top]=a[j];
            }
            for(int k=1;k<=top;k++)cnt[stk[k]]++;
        }
        for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
        cout<<endl;
    }
    return 0;
}
