#include<iostream>
#include<cstdio>
using namespace std;
int m,n,a[100000],j=1;
freopen("crystal.in",b,stdin);
int main(){
    b.getline(cin,n);
    b.getline(cin,m);
    for(int i=0;i<n;i++) {
        getline(cin,a[i]);

    }
    for(int i=0;;i++){
        if(i*a[i]<=m){
            j++;
            m-=i*a[i];
        }
        else{
            freopen("crystal.out",j,stdout);
            break;
        }
    }
}
