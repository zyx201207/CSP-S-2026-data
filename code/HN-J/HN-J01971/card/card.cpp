#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    bool cun="false";
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    int c[m];
    int x,y;
    for(int i=1;i<=n;i++){
        int b[n];
        for(int j=i-1;j<n;j++){
            b[j]=a[j];

        }
        for(int l=1;l<=n;l++){
            if(a[i-1]==b[l-1]&&i-1<l-1){
                for(int k=i-1;k<l-1;k++){
                    b[k]=0;
                }
        }
        }
        for(int h=1;h<=n;h++){
            for(int t=1;t<=m;t++){
                if(b[h]==t){
                    cun="true";
                }
                if£¨cun=="true"£©{
                    c[t]++;
                    cun=="false";
                }
            }
        }

    }
    for(int i-0;i<m;i++){
        cout<<c[i];
    }
    return 0;
}
