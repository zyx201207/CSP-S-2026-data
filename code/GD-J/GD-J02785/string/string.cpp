#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
long long a1=1;
string c;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        long long a;
        cin >> a;
        char b;
        cin >> b;
        for(int j=a1;j<=a1+a;j++){
            c[j] = b;

        }
        a1=a1+a;
    }

    for(int i=1;i<=a1/2;i++){
        if(c[i]!=c[a1-i+1]){

            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
