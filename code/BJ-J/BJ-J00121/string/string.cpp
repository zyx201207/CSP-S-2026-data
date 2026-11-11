#include<iostream>
#include<algorithm>
using namespace std;
int n,a[200005],ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    string s="";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s=s+c[i];
        }
    }
    for(int i=0;i<=s.size()/2;i++){
        if(c[i]!=c[s.size()-i]) ans++;
    }
    cout<<ans;
    return 0;
}
