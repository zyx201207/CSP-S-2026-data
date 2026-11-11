#include<bits/stdc++.h>
using namespace std;
int n;
vector<char>v;
vector<char>vf;
vector<char>vb;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long ai;
        char ci;
        cin>>ai>>ci;
        for(int j=1;j<=ai;j++){
            v.push_back(ci);
        }
    }
    long long sz=v.size();
    for(int i=0;i<=sz/2;i++){
        vf.push_back(v[i]);
    }
    for(int i=sz-1;i>=sz/2;i--){
        vb.push_back(v[i]);
    }
    for(int i=0;i<=(sz+1)/2;i++){
        if(vf[i]!=vb[i]&&vf[i]>='a'&&vf[i]<='z'&&vb[i]>='a'&&vb[i]<='z'){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
