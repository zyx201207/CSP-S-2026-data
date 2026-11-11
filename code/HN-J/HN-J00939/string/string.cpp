#include <bits/stdc++.h>

using namespace std;
long long ai,as,n;
string ns,bs;
//char bs;



int main()
{
    //ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //vector<long long> a;
    //vector<string> b;
    cin>>ai;
    //cout<<ai;
    for(long long i=0;i<ai;i++){
        //cout<<"go";
        cin>>as>>bs;
        //a.push_back(as);
        //b.push_back(bs);

        for(long long j=0;j<as;j++){
            //ns=bs;
            ns=ns+bs;
        }
    }
    //cout<<ns;
    //cout<<bs;
    int ans=0;
    for(long long i=0;i<ns.size()/2;i++){
        if(ns[i]!=ns[ns.size()-1-i]){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
