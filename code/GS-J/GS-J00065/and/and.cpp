#include<bits/stdc++.h>
using namespace std;
int s[100005];
int a[100005];
int u[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout)
    int n,m ;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int sum;
        for(int j=1;j<=i;j++){
            if(s[j]==a[i]){
                sum=i-j;
                for(int k=j;k<=sum;k++){
                    u[s[k]]=1*j;
                    s[k]==0;
                }
                s[j]=a[i];
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<u[i];
    }
    return 0;
}

