#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1;
long long a[1000001],t[1000001],le=0;
void choose(long long x,long long now,long long high){
    if(x==0){
        long long sumx=t[1];
        for(int i=1;i<=le;i++){
            if(t[i]!=0) sumx&=t[i];
        }
        maxn=max(maxn,sumx);
        return;
    }
    long long p=now;
    while(p<=high){
        t[++le]=a[p];
        choose(x-1,p+1,high);
        for(int i=p;i<=high;i++){
            t[i]=2147483647;
        }
        le=p;
        p++;
    }
    return;
}
int main(){
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    choose(m,1,n);
    cout<<maxn<<endl;
    return 0;
}
