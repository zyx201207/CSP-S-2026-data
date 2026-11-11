#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],b[500020],fA,fB,c[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=a[i-1])fA++;
    }
    if(fA==n){
        for(int i=1;i<=m;i++){
            cout<<i<<" ";
        }
        return 0;
    }
    else{
        b[1]=a[1];
        int f=1;
        while(f<=n){
            int r=f,l=f;
            while(l<=n){
                for(int i=f;i<=r;i++){
                    if(a[l]==a[i])r=i;
                }
                b[r]=a[l];
                r++;
                l++;
                //cout<<f<<" "<<r<<" "<<l<<endl;

            }
            for(int i=f;i<=r;i++){
                c[b[i]]++;
                //cout<<b[i]<<" ";
            }
            //cout<<endl;
            f++;

        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
