#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],rest[1000001],lis[1000001],lisle=0,store;
long long has(long long x,long long len){
    for(long long i=1;i<=len;i++){
        if(lis[i]==x) return i;
    }
    return -1;
}
void playandcalculate(long long time){
    for(long long i=1;i<=lisle;i++){
        lis[i]=0;
    }
    lisle=0;
    for(long long i=time;i<=n;i++){
        if(has(a[i],lisle)==-1) lis[++lisle]=a[i];
        else{
            store=has(a[i],lisle)-1;
            for(long long j=has(a[i],lisle);j<=lisle;j++){
                lis[j]=0;
            }
            lisle=store;
            lis[++lisle]=a[i];
        }
    }
    for(long long i=1;i<=lisle;i++){
        rest[lis[i]]++;
    }
}
int main(){
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        playandcalculate(i);
    }
    for(long long i=1;i<=m;i++){
        cout<<rest[i]<<" ";
    }
    cout<<endl;
    return 0;
}