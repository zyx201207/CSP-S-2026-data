#include <iostream>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int a,b,c;
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            cin >> c;
            if(long(c) / 2 != long(c)){
                c = long(c);
                cout << c;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
