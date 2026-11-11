#include<bits/stdc++.h>
using namespace std;
int a[10000000];
string b[1000000],c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<a[j];i++){
            c+=b[j];
        }
    }
    int s,z=0:
    s=c.size();
    for(int i=0;i<=s/2;i++){
        if(c[i]!=c[s-i]){
            z++;
        }
    }
    cout<<z;
    
    

    return 0;
}
