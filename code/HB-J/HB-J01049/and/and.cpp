#include<bits/stdc++.h>
using namespace std;
int er(int a){
    long long sum;
    while(a>0){
        sum=sum*10+a%2;
        a/2;
    }
    return sum;
}
int app(int a , int b){
    long long sum=0;
    while(a>0 && b>0){
        long long cut=0;
        if(a%10==b%10){
            int s=1;
            for(int i=1;i<cut;i++){
                s*=2;
            }
            sum+=s;
        }
        a=a/10;
        b=b/10;
        cut++;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >>n>>m;
    vector <long long> a(n+1);
    for(int i=1;i<=n;i++){
        cin >>a[i];
        a[i]=er(a[i]);
    }
    long long maxl=0;
    for(int i=n-1;i>0;i--){
        for(int j=1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                if(maxl<app(a[i],a[j])){
                    maxl=app(a[i],a[j]);
                }
            }
        }
    }
    cout <<maxl;
    return 0;
}
