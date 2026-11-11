#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1000010];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long fg[1000010];
    for(int i=1;i<=n;i++){
        int d[10000010],q=1,e=0;
        for(int j=i;j<=n;j++){
                if(q==1){
                    d[q]=a[j];
                    q++;
                    continue;
                }
            for(int k=i;k<q;k++){
                if(a[j]==d[k]){
                    e=k;
                    break;
                }
            }if(e!=0){
                for(int c=e;c<=q;c++){
                    d[c]=0;
                }
            }else{
                d[q]=a[j];
                q++;
            }
        }
        for(int p=1;p<=m;p++){
            for(int h=i;h<=q;h++){
                if(p==d[h]){
                    fg[m]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<fg[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}


