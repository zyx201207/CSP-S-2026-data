#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string sss;
    for(int i=0;i<n;i++){
        int a;
        string c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            sss+=c;
        }
    }
    string ssss;
    for(int i=sss.size()-1;i>=0;i--){
        ssss+=sss[i];
    }
    long long sum=0;
    for(int i=0;i<sss.size();i++){
        if(sss[i]!=ssss[i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
