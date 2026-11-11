#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string str;
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int k=1;k<=n;k++){
        char b;
        cin>>a[k]>>b;
        for(int j=1;j<=a[k];j++){
            str+=b;
        }
    }
    int m=str.size()/2;
    for(int i=1;i<=m;i++){
            if(str[i]!=str[str.size()-i +1]){
                ans++;
            }
        }
    cout<<ans;
    return 0;
}
