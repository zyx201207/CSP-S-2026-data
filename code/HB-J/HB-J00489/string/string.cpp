#include<bits/stdc++.h>
using namespace std;
int n,a[200010],l;
char c[200010];
int ans=0;
string s;
bool b=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    if(n==1)cout<<"0";
    if(n==2){
        if(c[1]=c[2])cout<<"0";
        else cout<<min(a[1],a[2]);
    }
    else {
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-i-1]){
                ans++;
            }
        }
    cout<<ans;
    }
    return 0;
}
