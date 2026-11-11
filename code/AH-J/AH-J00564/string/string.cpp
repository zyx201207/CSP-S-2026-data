#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int s=0;
    while(s>0){
        s += n % 10;
        n /= 10;
    }
    cout << s << endl;
    fclose(stdin);
    fclose(stdout);
return 0;
}
