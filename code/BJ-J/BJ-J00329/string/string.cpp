#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,a[10001];
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int gs[10001]={0};
    for(int i=1;i<=n;i++){
        int p=0,c[10001]={0},d[10001]={0},cs=0,b[10001],k=1;
        for(int j=i;j<=n;j++){
            if(c[a[j]]==0){
                c[a[j]]++;
                d[a[j]]=j;
                b[k]=a[j];
                cs++;
            }
            else{
                int q=1;
                while(b[q]!=a[i]) q++;
                for(int w=q;w<=k;w++){
                    d[a[b[w]]=0;
                    c[a[b[w]]=0;
                }
                c[q]=1;
                d[a[j]]=q;
                cs=cs-j+q;
                k=k-j+q;
                b[k]=a[j];
            }
        }
        for(int i=1;i<=cs;i++){
            gs[b[i]]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<gs[i]<<" ";
    }
    return 0;
}