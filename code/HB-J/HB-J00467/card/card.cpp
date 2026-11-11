#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n],b[m],c[n],d[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int k=0;k<m;k++){
        b[k]=0;
        d[m]=k+1;
    }
    for(int i=0;i<n;i++){
        int w=n;
        ans=0;
        for(int j=0;j<n;j++){
            c[j]=a[j];
        }
        for(int p=i;p<w;p++){
            for(int o=p;o<w;o++){
               if(c[p]==c[o]){
                    for(int k=0;k<=o-p;k++){
                        swap(c[p+k],c[o+k]);
                    }
                        for(int s=2*o-p+1;s<w;s++){
                            swap(c[o+ans],c[s]);
                            ans++;
                        }
                        w=w-o+p;
                        o=p;
                }
            }
            for(int o=0;o<w;o++){
                for(int k=0;k<m;k++){
                    if(c[o]==d[k]){
                        b[k]++;
                    }
                }
            }
        }
    }
    for(int k=0;k<m;k++){
        cout<<b[k]<<" ";
    }
    return 0;
}
