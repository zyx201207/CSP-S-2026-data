#include<bits/stdc++.h>
using namespace std;
int a[2000010];
char c[2000010];
long long mn;
long long js=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    vector<char> s[2000010];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    bool bj=false;
    for(int i=1;i<=n/2;i++){
        if(a[i]!=a[i-1]||c[i]!=c[i-1]){
            bj=true;
            break;
        }
    }
    if(bj==false){
        cout<<0;
        return 0;
    }
    bj=false;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            bj=true;
            break;
        }
    }
    int js=0;
    if(bj==false){
        for(int i=1;i<=n/2;i++){
            if(c[i]!=c[n-i+1]){
              js++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s[i].push_back(c[i]);
        }
    }
    for(int i=1;i<=n/2;i++){
        if(s[i]!=s[n-i+1]){
            js++;
        }
    }
    cout<<js*a[1];
    return 0;
}
