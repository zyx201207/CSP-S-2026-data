#include <bits/stdc++.h>
using namespace std;
const int N=5.1e5,M=3.1e5;
bool f;
long long n,m,a[N],mp[M],b[N],c[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i=0;i<=M;i++){
        mp[i]=-1;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            f=true;
        }
    }
    if(f==false){
        for(int i=1;i<=m;i++){
            cout<<n<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++) b[j]=0;
        for(int j=0;j<=M;j++) mp[j]=-1;
        for(int j=i;j<=n;j++){
            b[j]=a[j];
            if(mp[b[j]]!=-1){
                for(int k=mp[b[j]]+1;k<=n;k++){
                    mp[b[k]]=-1;
                    b[k]=0;
                }
            }
            else{
                mp[a[j]]=j;
            }
        }
        for(int j=1;j<=n;j++){
            if(b[j]!=0){
                c[b[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}