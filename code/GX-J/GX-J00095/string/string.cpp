#include <iostream>
using namespace std;

string data;
int n;

int main()
{
    cin >> n;
    for(int i = 0;i <= n;i++)
        cin >> data;
    for(int i = 0;i <= n;i++)
        cout << data[i] << " ";
    return 0;
}
