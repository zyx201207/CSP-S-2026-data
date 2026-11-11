#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long e[n];
    char f[n];
    string S;
    long long h=1;
    for(int i=0;i<n;i++){
        long long a;
        char c;
        cin>>a>>c;
        f[i]=c;
    	e[i]=a;
    }
    for(int i=0;i<n;i++){
        for(int j=h;j<=e[i]+h;j++){
            S[j]=f[i];
        }
        h+=e[i];
    }
    long long q=S.size();
    long long p=q/2;
    long long x=0;
    for(int i=1;i<=p;i++){
        if(S[i]!=S[q-i]){
            x+=1;
        }
    }
    cout<<x;
    return 0;
}
