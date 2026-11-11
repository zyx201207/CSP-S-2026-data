#include<bits/stdc++.h>
using namespace std;
int n,sum;
string s,t;
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int a;
    char c;
    for(int i=1;i<=n;i++){
        //cout<<i<<" "<<n<<endl;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
        sum+=a;
    }
    int len;
    len=sum/2;
    for(int i=sum-1;i>=0;i--){
        t+=s[i];
    }
    for(int i=0;i<len;i++){
        if(s[i]!=t[i]){
            ans++;
        }
    }
    //cout<<s<<endl<<t<<endl;
    cout<<ans;
    return 0;
}
