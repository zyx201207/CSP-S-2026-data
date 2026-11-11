#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,s=-1;
    char a;
    char l[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>a;
        for(int j=0;j<m;j++){
            s++;
            l[s]=a;
        }
    }
    int t=0,k;
    if(s%2==0){
        k=s/2;
    }else{
        k=s/2+1;
    }
    for(int i=0;i<k;i++){
        if(l[i]!=l[s-i]){
            t++;
        }
    }
    cout<<t;
    return 0;
    }
