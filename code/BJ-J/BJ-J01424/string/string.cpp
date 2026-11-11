#include<bits/stdc++.h>
using namespace std;
char c;
vector<char> a;
long long n,aa,ans,l;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>aa>>c;
        for(int j=1;j<=aa;j++){
            l++;
            a.push_back(c);
        }
    }
    
    for(int i=0;i<=l/2+1;i++){
        if(a[i]!=a[l-i-1]){
            cout<<i<<" "<<(l-i)<<endl;
            cout<<a[i]<<" "<<a[l-i]<<endl;
            ans++;
        }
    }cout<<ans;
    return 0;
}
