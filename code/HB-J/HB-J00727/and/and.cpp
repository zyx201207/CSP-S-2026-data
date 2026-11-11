#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int ejz(int n){
    int er=2;
    if(n==1){
        return 1;
    }
    else{
        for(int i=2;i<=n;i++){
            er=er*2;
        }
    }
    return er;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int  zhmax=0;
    int zh=0;
    int u,l;
    int o=1;
    for(int i=0;i<n;i++){
        for(int g=i+1;g<=i+m;g++){
            u=a[i];
            l=a[g];
            while(u!=0 && l!=0){
                if(u%2==1 && l%2==1){
                    zh=zh+ejz(o);
                }
                u=u/2;
                l=l/2;
                o++;
            }
            if(zh>zhmax){
                zhmax=zh;
            }
            zh=0;
            o=0;
        }
    }
    cout<<zhmax;

    return 0;
}
