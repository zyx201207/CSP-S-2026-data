#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    //aabbcd
    //abccba
    // vector<char> c(n+1);
    // vector<int> w(n+1);
    // vector<char> c1(n+1);
    //int p=0;
    string s="";
    for(int i=1;i<=n;i++){
        // cin>>w[i]>>c[i];
        // p=((p+w[i])&1);
        // c1[n-i+1]=c[i];
        int t;
        char c;
        cin>>t>>c;
        for(int i=1;i<=t;i++){
            s+=c;
        }
    }
    //cout<<s<<endl;
    long long cnt=0;
    long long si=s.size();
    for(int i=0;i*2<si;i++){
        int j=si-i-1;
        if(s[i]!=s[j]){
            //cout<<"not same at "<<i<<" "<<j<<"\n";
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
    //for(auto i:c1) cout<<i;
    // for(int i=1;i<=n;i++){
    //     for(int j=n;j-w[i]>=0;j--){

    //     }
    // }
}