#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;

int n,m;
int a[10010];
int ss[10010];
int ans[10010];

int fid(int k){
    for(int i=1;i<=n;i++){
        if(ss[i]==k)return i;
    }
    return -1;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    cout<<n<<m<<endl;;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //cout<<"@@@"<<endl;
    for(int i=1;i<=n;i++){
        memset(ss,0,sizeof(ss));
        //cout<<"@@@"<<endl;
        for(int j=i;j<=n;j++){
            if(fid(a[j])==-1){
                ss[j]==a[j];
            }
            else{
                for(int k=fid(a[j]);k<=j;k++){
                    ss[k]=0;
                }
            }
        }
        for(int j=1;j<=m;i++){
            if(fid(i)!=-1)ans[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
