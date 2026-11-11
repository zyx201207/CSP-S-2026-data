#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,v=0;
    long long m;
    cin>>n>>m;
    long long s[100005]={},c[100005]={};
    for(int i=0;i<n;i++){
          cin>>s[i];
    }
    sort(s,s+n);
    for(int i=1;i<n;i++){
        c[i]=s[i]-s[i-1];

    }
    for(int i=1;i<n;i++){
        int l=1;
        long long x=m;
        for(int j=i;j<n;j++){
            if(x>=c[j]*l){
                x-=c[j]*l;
                l++;
            }
            else break;
        }
        v=max(v,l);
    }
    cout<<v;
    return 0;
}
