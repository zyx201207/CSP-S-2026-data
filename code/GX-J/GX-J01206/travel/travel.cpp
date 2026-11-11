#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char r[3]={0};
    char x[3]={0};
    cin>>r[0]>>r[1]>>x[0]>>x[1];
    int a[5]={0};
    if(r[0]==x[0]){
        a[0]=1;
    }
    r[1]-='0';
    x[1]-='0';
    if(r[1]-x[1]<10||r[1]-x[1]>-10){
        a[1]=1;
    }
    if(a[1]==1){
        if(r[1]-x[1]<3||r[1]-x[1]>-3){
            a[2]=1;
        }
    }
    if(r[1]-x[1]<1&&r[1]-x[1]>-1){
        a[3]=1;
    }
    for(int i=0;i<4;i++){

        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
