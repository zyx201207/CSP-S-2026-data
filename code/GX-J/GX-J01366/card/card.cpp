#include<bits/stdc++.h>
using namespace std;
int yuan[500005],a[500005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>yuan[i];
    }

    for(int i=1;i<=n;i++){//

        for(int p=1;p<=n;p++){
            a[p]=0;
        }

        for(int j=i;j<=n;j++){
            a[j]=yuan[j];
            int f=0;

            for(int k=i;k<=j-1;k++){//shan
                if(a[k]==a[j]){
                    f=1;
                }
                if(f){
                    a[k]=0;
                }
            }

            //for(int i1=1;i1<=n;i1++){
            //    cout<<a[i1]<<" ";
            //}
            //cout<<endl;
        }


        for(int j=1;j<=n;j++){//tongji
            b[a[j]]++;
        }


    }
    for(int i1=1;i1<=m;i1++){
        cout<<b[i1]<<" ";
    }

    return 0;
}

