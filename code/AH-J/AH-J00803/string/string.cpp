#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int a[N];
string c[N];
string s,p;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s;
        while(a[i]--){
            p+=s;
        }
    }string f=p;
    reverse(p.begin(),p.end());
    if(f==p){
        cout<<0;
    }
    return 0;
}
