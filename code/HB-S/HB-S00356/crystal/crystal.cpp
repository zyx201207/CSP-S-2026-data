#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    cin>>n>>m;
    vector<long long> all(n);

    for(int i=0;i<n;i++){
        cin>>all[i];
    }

    sort(all.begin(),all.end(),less<long long>());

    unsigned long long ans =0;
    vector<long long> cha(n,0);

    for(int i=1;i<n;i++){
        cha[i]=all[i]-all[i-1];
        
    }
    for(int i=1;i<n;i++){
        cha[i]=cha[i]*i;
    }
    for(int i=0;i<n;i++){
        if(m>=cha[i]){
            m-=cha[i];
            ans+=1;
        }else{
            continue;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}