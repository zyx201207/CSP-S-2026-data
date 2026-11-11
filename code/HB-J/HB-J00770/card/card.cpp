#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int m,n;
int ans[M],a[N],t[M];
bool b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[j]=0;t[j]=0;
        }
        for(int j=1;j<i;j++)b[j]=1;
        for(int j=i;j<=n;j++){
            t[a[j]]++;
            if(t[a[j]]>1){
               // cout<<j<<endl;
                int k=j-1;
                t[a[j]]=1;
                b[j]=1;
                while(a[k]!=a[j]&&k>0){
                    if(b[k]==0){
                        b[k]=1;
                        t[a[k]]--;
                    }
                //    cout<<k<<endl;
                    k--;

                }

            }
        }
        for(int i=1;i<=n;i++){
            if(b[i]==0)ans[a[i]]++;
            //cout<<b[i];
        }//cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
