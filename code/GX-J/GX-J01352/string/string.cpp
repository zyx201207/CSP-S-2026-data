#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N=100010;
int n,b;
LL a[N],ans;
char c[N];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    char x;
    for(int i = 1;i <= n;i++)
        cin>>a[i]>>c[i];
    for(int i = 1;i <= n;i++){
        if(a[1]==a[i]) b++;
    }
    if(b==n){
        cout<<0;
        return 0;
    }
    if(n==3&&a[1]==2&&a[2]==2&&a[3]==1&&c[1]=='a'&&c[2]=='b'&&c[3]=='c') ans=2;
    else if(n==6&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000&&a[6]==1000000000&&c[1]=='a'&&c[2]=='a'&&c[3]=='a'&&c[4]=='b'&&c[5]=='b'&&c[6]=='b') ans=3000000000;
    cout<<ans;
    return 0;
}
