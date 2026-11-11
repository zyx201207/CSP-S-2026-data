#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
int n;
char c[N];
ll a[N];
string s="",tmp="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        tmp+=s[i];
    }
    if(s==tmp){
        cout<<0;
    }
    else{
        cout<<n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
