#include<bits/stdc++.h>
using namespace std;
long long d[500005],b[500005],w=0,w1[300005];
long long d1[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int c;
        cin>>c;
        d1[i]=c;
    }
    for(int i=1;i<=n;i++){
        int l=0;
        for(int i=1;i<=n;i++){
            d[i]=d1[i];
            b[i]=d1[i];
        }
        for(int j=i;j<=n;j++){
            int z=d[i];
            w=0;
            for(int i=1;i<=l+n;i++)
            {
                if(b[i]==z)
                {
                    w=i;
                    break;
                }
            }
            if(w>0){
                for(int o=w;o<=l+n;o++){
                    b[o]=0;
                }
                l++;
                b[l+n]=z;
            }else{
                l++;
                b[l+n]=z;
            }
        }
        for(int i=1;i<=l+n;i++){
            if(b[i]!=0){
                w1[b[i]]++;
                b[i]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(w1[i]!=0)
            cout<<w1[i]<<" ";
    }
    return 0;
}
