#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,ans=0,num=0;
    string x,sum;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>x;
        num+=a;
        for(int i=1;i<=a;i++){
            sum+=x;
        }
    }
    for(int i=0;i<num/2;i++){
        if(sum[i]!=sum[num-1-i]){
            ans++;
        }
    }
    cout<<ans;
}

