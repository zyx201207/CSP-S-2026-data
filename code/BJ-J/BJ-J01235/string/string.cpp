#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0,x;
    string a;
    char y;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        for(int i=1;i<=x;i++){
            a+=y;
        }
    }
    long long s=a.size()-1;
    for(int i=0;i<a.size()/2;i++){
        if(a[i]!=a[s-i]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
