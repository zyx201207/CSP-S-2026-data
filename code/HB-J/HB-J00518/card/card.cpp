#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int b[1000000];
int c[1000000];
bool d[1000000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
                int S=0;
            for(int l=i;l<j;l++){
                if(b[l]==a[j]){
                    S=1;
                    for(int x=l+1;x<=n;x++){
                        b[x]=0;
                    }
                        break;
                }
            }
            if(S==0){
                b[j]=a[j];
            }
        }
       for(int l=1;l<=m;l++){
        for(int j=1;j<=n;j++){
            if(b[j]==l && d[l]==0){
                c[l]++;
                d[l]=1;
            }
        }
    }
    for(int j=1;j<=n;j++){
        b[j]=0;
        d[j]=0;
    }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
        return 0;
}
