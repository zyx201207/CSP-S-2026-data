#include<bits/stdc++.h>
using namespace std;
int n,a,cnt;
long long sum;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a>>c;
        sum+=a;
        for(int j = 1;j<=a;j++){
            s+=c;
        }
    }
    for(int l = 0;l<sum/2;l++){
        int r=sum-l-1;
        if(s[l]!=s[r])cnt++;
    }
    cout<<cnt;
    return 0;
}
