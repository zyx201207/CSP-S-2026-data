#include <iostream>
using namespace std;
int a[10001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,b;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b;
    }
    if(n==1){
        cout << 0;
    }
    if(n==2){
        if(a[1] > a[2]){
            cout << a[1];
        }
        else{
            cout << a[2];
        }
    }
    fclose(stdin);
    fclose(sfdout);
}
