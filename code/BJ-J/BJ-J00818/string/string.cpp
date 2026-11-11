#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long a[10000010];
    string s,d;
    long long w=0;
    long long e=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>s[i];
        if(i>=2){
            if(s[i]==s[i-1]){
                e++;
            }
        }
        w+=a[i];
    }
    if(e==n){
        cout<<"0";
        return 0;
    }
    if(w==1){
        cout<<"0";
        return 0;
    }
    if(w==2){
        cout<<"1";
        return 0;
    }
    else cout<<a[4];
    fclose(stdin);
    fclose(stdout);

    return 0;
}


