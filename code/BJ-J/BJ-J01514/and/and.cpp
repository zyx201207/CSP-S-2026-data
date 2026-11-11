#include<bits/stdc++.h>
using namespace std;
long long num[11450014];
long long a,b;
long long bigestN=-1;
long long ce(long long now,long long ans,long long numer){

    ans=ans&num[now];

    for(long long i=1;i<a-now;i++){
        ce(now+i,ans,numer+1);
    }
    if(numer==b){
        if(ans>=bigestN){
            bigestN=ans;

        }
        return 0;
    }
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(long long i=0;i<a;i++){
        cin>>num[i];
    }
    for(long long i=0;i<=a-b;i++){
        ce(i,num[i],1);
    }
    cout<<bigestN;
    return 0;
}



