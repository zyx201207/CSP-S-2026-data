#include<bits/stdc++.h>
using namespace std;
string s;
long long k=0,l=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            k++;
            s[k]=c;
        }
    }
    for(int i=1;i<=k/2;i++){
        if(s[i]!=s[k+1-i]){
            l++;
        }
    }
    cout<<l;
    return 0;
}

