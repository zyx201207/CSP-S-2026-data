//GZ-J00382;山水中学;史睿琦//
#include <iostream>;
using namespace std;
int main(){
    int n,m,s;
    string a;
    s = 0;
    cin >> n,m;
    while(s < n){
        cin >> a;
    }
    if (a[0] > a[m-1]){
        cout << a[0];
    }else{
        cout << a[m-1];
    }
    return 0;
}
