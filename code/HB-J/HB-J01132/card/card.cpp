#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[300001]={},b[300001]={},c[300001]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[1]==0){
                b[1]=a[j];
            }
            else{
                for(int k=1;k<=n;k++){
                    if(b[k]==a[j]){
                        for(int q=k;q<=j;q++){
                            b[q]=0;
                        }
                        b[k]=a[j];
                        break;
                    }
                    if(b[k]==0){
                        b[k]=a[j];
                        break;
                    }
                }
            }
        }
        for(int k=1;k<=m;k++){
                c[b[k]]++;
        }
        for(int j=1;j<=m;j++){
            b[m]=0;
        }
    }
    for(int j=1;j<=m;j++){
        cout<<c[m]<<" ";
    }
    cout<<endl;
    return 0;
}
