#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s=0,sum=0;
    int a[n+1];
    char b[n+1];
    int q=1,w=1,e=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    char x[sum+1];
    for(int i=1;i<=sum;i++){
        if(q<=a[w]){
            x[i]=b[e];
        }else{
            x[i]=b[e+1];
            q=1;w++;e++;
        }q++;
    }
    int z;
    int d=sum;
    if(sum%2==0){
        z=sum/2;
    }else{
        d-=1;
        z=d/2;
    }
    for(int i=1;i<=z;i++){
        if(x[i]!=x[sum-i+1]){
            s++;
        }
    }cout<<s;
    return 0;
}
