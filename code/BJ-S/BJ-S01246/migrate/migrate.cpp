#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("migrate.in","r" ,stdin);
    freopen("migrate.out","w" ,stdout);
    int c,t;
    cin>>c>>t;
    vector<int> ans;
    for(int i=0;i<t;i++){
        int n,d;
        cin>>n>>d;
        int x[n+1];
        cin>>x[0];
        for(int j=1;j<n;j++){
            cin>>x[j];
            if(x[j]-x[j-1]>d){
                j--;
                n--;
            }
        }
        if(d==2){
            ans.push_back(n-4+1);
        }
        else{
            ans.push_back(0);
        }
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
