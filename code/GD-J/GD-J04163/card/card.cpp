#include<bits/stdc++.h>
using namespace std;
int b[50000];
int lstA[50000];
int app[50000];
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int bend=0;
    for(int i=0;i<n;++i){
        for(int i=0;i<50000;++i)lstA[i]=-1;
        bend=0;

        for(int j=i;j<n;++j){
            if(lstA[a[j]]!=-1){
                bend=lstA[a[j]];
                lstA[a[j]]=bend;
            }lstA[a[j]]=bend++;b[bend-1]=a[j];
        }
        for(int j=0;j<bend;j++) ++app[b[j]];
    }
    for(int i=1;i<=m;++i){
        cout<<app[i]<<" ";
    }
}