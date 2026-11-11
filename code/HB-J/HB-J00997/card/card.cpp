#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int h[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,c=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int l=1;l<=c;l++){
                if(b[l]==a[j]){
                    //cout<<j<<" "<<l<<" "<<b[l]<<" "<<a[j]<<"\n";
                    for(int k=l;k<=c;k++){
                        b[k]=0;
                    }
                    c=l-1;
                    break;
                }
            }
            b[++c]=a[j];
            /*
            for(int j=1;j<=c;j++){
                //h[b[j]]++;
                cout<<b[j]<<" ";
            }
            cout<<"\n";
            */
        }
        for(int j=1;j<=c;j++){
            h[b[j]]++;
            b[j]=0;
        }
        //cout<<"\n";
    }
    //cout<<c;
    for(int i=1;i<=m;i++){
        cout<<h[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
