//GZ-J00279 程子洋
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a;
    int b;
    int c;
    int s;
    int d[10000];
    int e[10000];
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c;
        d[i]=c;
    }
    for(int i=0;i<a;i++){
        if(d[i]<d[i+1]){
            a=d[i];
            d[i]=d[i+1];
            d[i+1]=a;
        }
    }
    for(int i=0;i<b;i++){
       e[i]=d[i];
    }
    for(int i=0;i<b-1;i++){
       if(e[i]>e[i+1]){
            s=e[i+1];
       }else{
           s=e[i];
       }
    }
    cout<<s;
return 0;
}
