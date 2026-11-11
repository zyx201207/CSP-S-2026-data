#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    int l=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(log2(a[i])>l){
            l=log2(a[i]);
        }
    }
    bitset<32> w=a[0];
    int b[n][32];
    for(int i=0;i<n;i++){
    bitset<32> w=a[i];
        for(int j=0;j<32;j++){
            b[i][j]=w[j];
           // cout<<w[j]<<' ';
        }
       // cout<<endl;
    }
  //  cout<<l<<endl;
    bool no[n]={};
    for(int i=l;i>=0;i--){
         //   cout<<i<<"--";
        int s=0;
        for(int j=0;j<n;j++){
            if(b[j][i]==1 and no[j]==0){
                s++;
            }
        }
       // cout<<" s="<<s<<"   ";
        if(s>=m){
            if(s==m){
                int z=-1;
                for(int j=0;j<n;j++){
                    if(b[j][i]==1 and z==-1){
                        z=a[j];
                    }
                    if(b[j][i]==1){
                        z=z&a[j];
                    }
                }
                cout<<z;
                return 0;
            }
            else{
            for(int j=0;j<n;j++){
            if(b[j][i]==0){
                no[j]=1;

            }
           // cout<<no[j]<<' ';
        }//cout<<endl;
            }

        }

    }
    int z=-1;
    for(int j=0;j<n;j++){
        if(no[j]==0 and z==-1){
            z=a[j];
        }
        if(no[j]==0){
            z=z&a[j];
        }
    }
    cout<<z;
}
