#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ma[19005][19005],m,n,d,q,c,k,t[50005],a[50005],z[50006],ji[100005][2];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>z[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k-1;j++){
            for(int l=j+1;l<=k;l++){
                ma[a[j]][a[l]]=t[j]+t[l];
                ma[a[l]][a[j]]=t[j]+t[l];
            }
        }
    }
 /*   for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<setw(4)<<ma[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(ma[i][k]!=0&&ma[k][j]!=0&&ma[i][j]==0){
                    ma[i][j]=ma[i][k]+ma[k][j];
                }
                else if(ma[i][k]!=0&&ma[k][j]!=0&&ma[i][j]!=0){
                    ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
                }

            }
        }
    }
 /*   for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<setw(4)<<ma[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=q;i++){
        cin>>ji[i][0]>>ji[i][1];
        cout<<(ma[ji[i][0]][ji[i][1]]+z[ji[i][0]]+z[ji[i][1]])<<endl;
    }
    return 0;
}
