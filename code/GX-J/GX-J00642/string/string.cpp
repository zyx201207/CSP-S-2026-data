#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        char x;
        cin>>x;
        for(int i=0;i<t;i++){
            a.push_back(x);
        }
    }
    while(a.size()>1){
        if(a[0]==a[a.size()-1]){
            a.erase(a.end()-1,a.end());
            a.erase(a.begin(),a.begin()+1);
        }
        else{
            a.erase(a.end()-1,a.end());
            a.erase(a.begin(),a.begin()+1);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
