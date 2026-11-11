#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","m",stdout);
    int n=0;
    cin >>n;
    long long a[n]={0};
    char c[n]={0};
    string h=" ";
    for(int i=0;i<n;i++){
        cin >>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            h+=c[i];
        }
    }
    long long z=0;
    for(int i=0;i<n;i++){
        if(h[i]!=h[n-i]){
            h[i]=h[n-i];
            z++;
        }else{
        cout <<z;
        break;
        }
    }
    return 0;
}
