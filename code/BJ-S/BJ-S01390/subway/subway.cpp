#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,v,c,d=0;
    cin>>n>>m;
    long long a[m],s[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            a[j]=s[d];
            d=d+1;
        }
        for(int w=0;w<m-i;w++){
            c=s[w+1];
            if(c>s[w]){
                v=c;
            }
            else{
                v=s[w];
            }
            w=w+1;
        }
        a[i]=v;
        cout<<a[i]<<" ";
    }
    int i=1;
    while(n>0){
        n=n-(a[0]-a[i]);
        i=i+1;
    }
    i=i-1;
    cout<<i;
    return 0;
}
