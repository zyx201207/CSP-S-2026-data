#include<bits/stdc++.h>
using namespace std;
long long t[300005];
long long a[500005];
long long m1[300005];
long long t1[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            m1[j]=0;
        }
        for(int j=1;j<=n;j++){
            t1[j]=0;
        }
        for(int j=i;j<=n;j++){
            t[a[j]]++;
        }
        for(int j=i;j<=n;j++){
            if(m1[a[j]]==0){
                m1[a[j]]=j;
            }else{
                for(int x=m1[a[j]];x<j;x++){
                    t1[x]=1;
                    m1[a[x]]=0;
                }
                m1[a[j]]=0;
                j--;
            }
        }
        for(int j=i;j<=n;j++){
            if(t1[j]==1){
                t[a[j]]--;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
