#include<iostream>
using namespace std;
long long a[200005],ant;
string str = "0";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char b;
        cin >> a[i] >> b;
        for(int j = 1; j <= a[i]; j++){
            str += b;
        }
    }
    for(int i = 1; i <= ((str.length() - 1) / 2); i++){
        if(!(str[i] == str[(str.length() -1) + 1 - i])){
            ant++;
        }
    }
    cout << ant;
    return 0;
}
