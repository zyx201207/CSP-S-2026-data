#include<bits/stdc++.h>
using namespace std;
long long v[210000],n,s=0;char a[210000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>a[i];
    }
    int i=0,j=n;
    while(i<j){
        if(a[i]!=a[j])s+=min(v[i],v[j]);
        if(v[i]<v[j]){
            v[j]-=v[i];
            i++;
        }else if(v[i]==v[j]){
            j--;
            i++;
        }else{
            v[i]-=v[j];
            j--;
        }
    }
    cout<<s;
    return 0;
}

