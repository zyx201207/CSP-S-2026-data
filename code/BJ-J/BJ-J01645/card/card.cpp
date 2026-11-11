#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[500010],b[300010],bj[300010],t[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bj[j]=0;
        }
        for(int j=i;j<=n;j++){
            b[j]=a[j];
        }
        for(int j=i;j<=n;j++){
            //cout<<bj[b[j]]<<" ";
            if(!bj[b[j]]) bj[b[j]]=j;
            else{

                for(int k=bj[b[j]]+1;k<j;k++){
                    bj[b[k]]=0;
                    b[k]=0;

                }
                bj[b[j]]=j;
            }
        }
        //for(int j=1;j<=m;j++){
            //cout<<bj[j]<<" ";
        //}
        int te[500010];
        for(int j=1;j<=m;j++)te[j]=0;
        for(int j=i;j<=n;j++){
            te[b[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(te[j]){
                t[j]++;
                //cout<<j<<" ";
            }
        }
        //cout<<endl;

    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
