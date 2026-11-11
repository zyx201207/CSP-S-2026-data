#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[101010]={0},c[101010]={0};
    string b="";
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
                if(b.find(a[i])==-1){
                    b+=a[i];
                }else{
                    b.substr(b.find(a[i]),b.size()-1);
                }
        }
        for(int i=1;i<=m;i++){
            if(b.find(i)!=-1){
                c[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}

