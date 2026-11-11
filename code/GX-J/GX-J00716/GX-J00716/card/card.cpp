//yi yan bu he wei wo yi zui da mo ni sha yi si
#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int di=0;
    int d[m]={};
    int t[n]={};
    for(int i=0;i<n;i++){
        for(int j=i;i<n;j++){
            for(int k=0;k<j;k++){
                if(d[k]==a[j]){
                        di=k+1;
                    for(int l=k+1;l<j;l++){
                        d[l]=-1;
                    }
                }else{
                    d[di]=a[j];
                }
            }

            di++;


        }
        for(int j=0;j<=di;j++){
            t[d[j]] ++;
        }
    }
    for(int i=0;i<=di;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}




