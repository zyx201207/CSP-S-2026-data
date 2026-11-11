#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    return gcd(b,a%b);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,k,nk,maxx=-1,maxx2=-1;cin>>n>>k;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        if(i==0)nk=temp;
        else{nk=nk&temp;}
        if(maxx<temp)maxx=temp;
        v.push_back(temp);
    }
    if(n==k){
        cout<<nk;
        return 0;
    }
    if(k==1){
        cout<<maxx;
        return 0;
    }
    if(k==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=gcd(v[i],v[j]);
                if(maxx2<temp)maxx2=temp;
            }
        }
        cout<<maxx2;
    }
    return 0;
}
