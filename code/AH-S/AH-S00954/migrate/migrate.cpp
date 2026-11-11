#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long island;//岛屿数量
long long flying;//距离
long long isl[100005]={0};//间隔
long long islong[100005]={0};//差值
long long sum=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>island>>flying;
        for(int j=0;j<island;j++){
            cin>>isl[j];
        }
        for(int j=island-1;j>=1;j--){
            islong[j]=isl[j]-isl[j-1];
        }
        for(int j=1;j<island;j++){
            islong[j]+=islong[j-1];

        }
        for(int j=1;j<island;j++){
                for(int k=1;k<j;k++){
                    if((islong[j]-islong[j]%flying)/flying==1 and islong[j]%flying ==1 or ((islong[j]-islong[k])-(islong[j]-islong[k])%flying)/flying and (islong[j]-islong[k])%flying==1){
                        sum++;
                    }
                }
        }
        cout<<sum-1;
        sum=0;
        island=0;
        flying=0;
        isl[100005]={0};
        islong[100000]={0};
    }
    return 0;
}
