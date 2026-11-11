#include <iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n,ans=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        while(a--){
            s=s+c;
        }
    }
    int l=s.size();
    for (int i=0;i<l/2;i++){
        if (s[i]!=s[l-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
