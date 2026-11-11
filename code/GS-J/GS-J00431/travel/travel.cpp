#include <iostream>
using namespace std;
//a[5][18];
//int a, b, c, d;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, b, c, d;
    cin >> a, b, c, d;
    if(a == c){
        if(b = d - 1 || d = b - 1){
            cout << 1111;
        }
        else{
            cout << 1110;
            return 0;
        }
    }
    else{
        cout << 1110;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
