#include <bits/stdc++.h>
using namespace std;
int n,m,top;
int a[500001],s[500001];
int ans[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<5000){
        for(int i=1;i<=n;i++){
            top=0;
            for(int j=i;j<=n;j++){
                bool f=1;
                for(int k=1;k<=top;k++){
                    if(a[j]==s[k]){
                        f=0;
                        top=k;
                        break;
                    }
                }
                if(f==1) ++top,s[top]=a[j];
            }
            for(int k=1;k<=top;k++)
                ans[s[k]]++;
        }
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<' ';
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]) a[i]=0;
        }
        for(int i=1;i<=n;i++){
            ans[a[i]]=i;
        }
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<' ';
        return 0;
    }
}
