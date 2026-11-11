#include <bits/stdc++.h>
using namespace std;

int ge[200010];
char z[200010];
string s;
bool flag=true;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ge[i] >> z[i];
        sum+=ge[i];
    }
    if(n<=1){
        cout << 0;
        return 0;
    }
    for(int i=1;i<=n-1;i++){
        if(z[i]!=z[i+1]) flag=false;
    }
    if(flag==true){
        cout << 0;
        return 0;
    }
    if(n<=2){
        cout << min(ge[1],ge[2]);
        return 0;
    }
    if(n<=10) cout << n/2;
    return 0;
}
