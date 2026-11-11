#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s[100000005];
    int n,cnt=1,sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        long long a,b;
        cin >> a >> b;
        for(int j=1;j<=a;j++){
            s[cnt]+=b;
            cnt++;
        }
    }
    int l=1,r=cnt-1;
    while(r>l){
        if(s[l]!=s[r]){
            sum++;
        }else{
            l++;
            r--;
        }
    }
    cout << sum;
    return 0;
}


