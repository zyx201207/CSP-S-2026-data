#include<bits/stdc++.h>
using namespace std;
string s[2147483640];
string ss;
int main(){
    freopen("string.in","r",stadin);
    freopen("string.out","a",stadout);
    int n,a[2147483640],ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            ss+s[i];
        }
    }
    int k=ss.size();
    for(int i=0;i<ss.size()/2;i++){
        if(ss[i]!=k){
            ans++;
            k--;
        }
    }
    cout<<ans;
    return 0;
}
