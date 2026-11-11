#include<iostream>
#include<map>
using namespace std;

size_t comax(int*arr,size_t n){
    map<int,size_t> counter;
    size_t man=0;
    for(int i=0;i<n;i++){
        counter[arr[i]]++;
        if(counter[arr[i]]>man)man=counter[arr[i]];
    }
    return man;
}

int f(int*stone,size_t n,size_t m){
    if(m==0) return comax(stone,n);
    int res=0;
    for(int goal=0;goal<n;goal++)for(int i=0;i<n;i++)if(stone[i]!=stone[goal]&&stone[i]<stone[goal]){
        int old=stone[i];
        stone[i]=stone[goal];
        res=max(res,f(stone,n,m-stone[goal]+old));
        stone[i]=old;
    }
    return res;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    size_t n,m;cin>>n>>m;
    int *stone=new int[n];
    for(int i=0;i<n;i++)cin>>stone[i];
    cout<<f(stone,n,m)<<endl;
    return 0;
}
