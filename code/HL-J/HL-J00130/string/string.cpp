#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int a;
string  c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    int le=s.size();
    cout<<le/2;
    return 0;
}

