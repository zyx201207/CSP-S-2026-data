#include<iostream>
using namespace std;
string x1, x2, z1, z2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> x1 >> z1 >> x2 >>z2;
    if(x1 != x2){
        cout << "0000";
        return 0;
    }
    cout << '1';
    if(z1[0] != z2[0] || z1[1] != z2[1]){
        cout << "000";
        return 0;
    }
    cout << '1';
    if(z1[2] != 'D' && z1[2] != 'F' && z2[2] != 'D' && z2[2] != 'F'){
        cout << '1';
        if(z1[2] == z2[2] + 1 || z1[2] + 1 == z2[2]){
            cout << '1';
        }else
        {
            cout << '0';
        }
    }else if((z1[2] == 'D' || z1[2] == 'F') && (z2[2] == 'D' || z2[2] == 'F'))
    {
        cout << '1';
        if(z1[2] == z2[2] + 2 || z1[2] + 2 == z2[2]){
            cout << '1';
        }else
        {
            cout << '0';
        }
    }else {
        cout << "00";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
