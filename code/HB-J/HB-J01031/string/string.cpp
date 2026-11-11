#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string t;
    int n;
    cin>>n;
    long long a;
    char c;
    long long w = 0;
    for(int i = 0;i<n;i++){
        cin>>a>>c;
        for(long long j = w;j<w+a;j++){
            t[j] = c;
        }
        w = w+a;
    }
    int as = 0;
    for(int i = 0;i<=w/2;i++){
        if(t[i]!=t[w-i-1]){
           as++;
        }
    }
    cout<<as;
    return 0;
}
