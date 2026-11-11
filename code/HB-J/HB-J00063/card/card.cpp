#include<bits/stdc++.h>
using namespace std;

long long a[1000000005];
long long s[1000000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        if(s[a[i]]>i){
            while(a[i]!=a[i-1]){
                s[a[i]]-=2;
            }
            for(int j=1;j<=m;j++){
                s[a[i]]++;
            }
        }
        for(int k=1;k<=m;k++){
            s[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << s[i] << " ";
    }
    return 0;
}
