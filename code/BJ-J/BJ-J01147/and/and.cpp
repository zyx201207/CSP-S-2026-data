#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define int long long
int n,m;
int ans=-10000;
vector<int> aa;
void aaa(int a1,int a2,int k){
    for(int i=a2+1;i<n;i++){
        if(k==1){
            ans=max(ans,a1&aa[i]);
        }else{
                aaa(a1&aa[i],i,k-1);
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int z;
        cin>>z;
        aa.push_back(z);
    }
    for(int i=0;i<n;i++){
        aaa(aa[i],i,m-1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
