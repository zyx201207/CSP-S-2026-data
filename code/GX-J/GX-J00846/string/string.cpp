#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char p;
    int a[1005];
    int n,m = 0;
    cin >> n;
    int b;
    for(int i = 0;i < n;i++){
        cin >> b;
        cin >> p;
        for(int j = 0;j < b;j++){
            a[m] = p;
            m++;
        }
    }
    b = 0;
    for(int i = 0;i < a.size();i++){
        if(a[i] != a[a.size()-1]){
        a[a.size()-1] = a[i];
        b++
        }
    }
    cout << b;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
