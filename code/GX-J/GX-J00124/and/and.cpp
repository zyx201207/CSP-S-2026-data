#include<bits/stdc++.h>
using namespace std;

int mandf(int* andline,int and1,int andsize,int dg,int and2){
    int msize=andsize-and1-1;
    int a[msize]={};
    for(int i=and1+1;i<andsize;++i){
        a[i-and1-1]=(and2&(*(andline+i)));
    }
    sort(a,a+msize-1);
    if(dg==1){
        return a[msize-1];
    }else{
        return mandf(andline,and1+1,andsize,dg-1,a[msize-1]);
    }
}
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdin);
    cin>>n>>m;
    int nline[n]={};
    for(int i=0;i<n;++i){
        cin>>nline[i];
    }
    cout << mandf(nline,0,n,m,2147483647);
    return 0;
}
