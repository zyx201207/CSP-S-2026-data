#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    string s;
    for(int i=1;i<=n;i++){
        long long a;string c;
        cin >> a >> c;
        for(int w=0;w<a;w++){
            s=s+c;
        }
    }
    long long lo=s.size();
    bool wh=0;
    for(int e=1;e<lo/2;e++){
        if(s[e]=s[e-1]) wh=1;
        else wh=0;
    }
    int we=0;
    for(int i=0;i<=lo/2;i++){
        if(wh=1)break;
        if(s[i]!=s[lo-1]){
        s[lo]=s[i];
        we++;
       lo--;
        }

    }
    if(wh=1)cout <<lo/2;
    else cout <<we;
    return 0;
}
