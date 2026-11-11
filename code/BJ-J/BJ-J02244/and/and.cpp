#include<bits/stdc++.h>
using namespace std;

int nu[200001];
bool no[200001];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn=0,mmaxn=0,place,mmm=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>nu[i];
    }
    for(int i=0;i<n;i++){
        maxn=nu[i];
        no[i]=1;
        for(int x=0;x<m;x++){
            for(int j=0;j<n;j++){
                if(mmaxn&nu[j]>maxn&&!no[j]){
                    maxn=mmaxn&nu[j];
                    place=j;
                }
            }
            mmaxn=maxn;
            maxn=0;
            no[place]=1;
        }
        if(mmaxn>mmm){
            mmm=mmaxn;
        }
        mmaxn=0;
        for(int j=0;j<n;j++){
            no[j]=0;
        }
    }
    cout<<mmm;
    return 0;
}