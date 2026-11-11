#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,s;
char c[200005];
string b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    fclose(stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            b+=c[i];
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]!=b[n-1-i]){
            s++;
        }
    }
    cout<<s;
    return 0;
}
