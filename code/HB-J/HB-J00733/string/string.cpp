#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long a[200005];
    string c[200005];
    string s;
    int n;
    int b=0,t=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for (int j=1;j<=a[i];j++){
            s+=c[i];
            b++;
        }
    }

    for (int i=b/2-1;i>=0;i--){
        if(s[i]!=s[b-i-1]){
            t++;
        }
    }
    cout << t;


    return 0;
}
