#include<bits/stdc++.h>
using namespace std;
int n,m;
int w[300010];
int a[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int ia[500010];
        int it=0;
        for(int j=i;j<=n;j++){
            //int fl=0;
            for(int k=1;k<=it;k++){
                if(ia[k]==a[j]){
                    //fl=1;
                    it=k-1;
                    //cout<<"%";
                    break;
                }
            }
            ia[++it]=a[j];

        }
        //for(int j=1;j<=it;j++){
            //cout<<a[j]<<" ";
        //}
        //cout<<endl;
        for(int j=1;j<=it;j++){
            w[ia[j]]+=1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<w[i]<<" ";
    }
    return 0;
}
