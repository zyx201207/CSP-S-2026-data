#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int x,y;
    int ans = 0;
    int num = 0;
    long long s[1000000005];
    cin >> x >> y;
    for(int i = 0;i < x;i++){
        cin >> s[i]
        if(y == x)
            ans = num & s[i];
            num = ans;
    }
    cout >> ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
