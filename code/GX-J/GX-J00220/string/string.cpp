#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin>>n;
    char c[n];
    string s;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i-1]>>c[i-1];
        for(int b=0;b<a[i-1];b++){
            s+=c[i-1];
        }
    }
    for(int d=0;d<n;d++){
        for(int e=0;e<s.length()-1;e++){
            if(s[e]!=c[d])
                sum+=1;
        }
        cout<<sum;
    }

    return 0;
}
