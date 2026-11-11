#include<bits/stdc++.h>
using namespace std;
const int N=200001;
long long n,ans;
long long a[N];
string s[N],t,y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        for(int j=1;j<=a[i];j++){
            t+=s[i];
        }
    }
    int j=t.size();
    for(int i=1;i<=t.size();i++){
        y[j]=t[i];
        j--;
    }
    for(int i=1;i<=t.size();i++){
        if(y[i]!=t[i]){
            ans++;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}