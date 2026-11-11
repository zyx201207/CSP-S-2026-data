#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=-1,b[200005],num=0;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
		char a;
        cin>>b[i]>>a;
        for(int j=1;j<=b[i];j++){
            s+=a;
        }
        num+=b[i];
    }
    for(int i=0;i<num;i++){
        if(s[i]!=s[num-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
