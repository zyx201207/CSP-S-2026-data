#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k[n],ans[m+5];
    for(int i=0;i<m+5;i++){
        ans[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    for(int t=0;t<n;t++){
        int li=0;
        int l[n];
        int c[m+5];
        for(int j=0;j<m+5;j++){
            c[j]=0;
        }
        for(int i=t;i<n;i++){
            l[li++]=k[i];
            if(c[k[i]]){
                for(int j=0;j<li;j++){
                    if(l[j]==k[i]){
                        li=j+1;
                        break;
                    }
                }
            }
            for(int j=0;j<m+5;j++){
                c[j]=0;
            }
            for(int j=0;j<li;j++){
                c[l[j]]++;
            }
        }
        for(int i=0;i<li;i++){
            ans[l[i]]++;
        }
    }
    for(int i=1;i<m+1;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
