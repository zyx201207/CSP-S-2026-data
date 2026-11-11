#include <bits/stdc++.h>
using namespace std;
int n,m,b[300005],c[300005],d[300005];
int main()
{
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        q=i-1;
        for(int j=1;j<=m;j++) c[j]=0;
        for(int j=i;j<=n;j++){
            if(c[a[j]]!=0){
                for(int k=i;k<=q;k++){
                    if(b[k]==a[j]){
                        for(int z=i;z<=q;z++){
                            b[z]=0;
                            q--;
                        }
                        break;
                    }
                }
            }else{
            c[a[j]]++;
            b[q]=a[j];
            q++;
            }
        }
        for(int j = i;j<=q;j++) d[j]++;
    }
    for(int i=1;i<=m;i++) cout<<d[i]<<" ";
    return 0;
}