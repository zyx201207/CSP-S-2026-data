#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);*/
    int n,m;
    cin>>n>>m;
    int s[n+1],t[n+1]={0};
    int r[m+1]={0};
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        t[n+1]={0};
        for(int j=i;j<=n;j++){
            t[j]=s[j];
        }
        for(int j=0;j<i;j++){
            if(t[i]==t[j]){
                for(int l=0;l<i;l++){
                    t[l]=0;
                }
            }
        }
        for(int j=i;j<=n;j++){
            for(int l=1;l<=m;l++){
                if(t[j]==l){
                    r[l]+=1;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<r[i]<<" ";
    }
    return 0;
}
