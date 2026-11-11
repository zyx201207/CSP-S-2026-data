#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);

    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;

    bool arr[4] = {false , false , false , false};

    if (c1 == c2)arr[0] = true;
    if (s1.substr(0 , 2) == s2.substr(0 , 2) && arr[0])arr[1] = true;
    int a = 2 , b = 2;
    if (s1[2] == 'F' || s1[2] == 'D')a = 1;
    if (s2[2] == 'F' || s2[2] == 'D')b = 1;

    if (a == b && arr[1])arr[2] = true;
    if ((s1[2]+1 == s2[2] || s1[2]-1 == s2[2]) && arr[2])arr[3] = true;

    for(int i = 0 ; i < 4 ; i ++){
        cout << int(arr[i]);
    }


    return 0;
}
