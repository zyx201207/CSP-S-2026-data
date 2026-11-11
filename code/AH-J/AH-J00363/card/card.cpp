#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m;
int a[500005],c[500005],t[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++){
            if(t[a[j]]==0){
                t[a[j]]=j;
            }else{
                for(int k=t[a[j]];k<=j;k++){
                    t[a[k]]=0;
                }
                t[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(t[j]!=0){
                //cout<<a[j]<<" ";
                c[j]++;
            }
        }
        //cout<<endl;
    }
    for(int j=1;j<=m;j++){
        cout<<c[j]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
